from ctypes import *


class A(Structure):
    _fields_ = [
        ("a1", c_char_p),
        ("a2", c_int)]


class Callback(object):
    def output_Callback(self, a, b):
        print(a.contents.a1, a.contents.a2)
        print(b)


def cb(a, b):
    print(dir(a))
    print(a.contents.a1, a.contents.a2)
    print(b)

CMPFUNC = CFUNCTYPE(None, POINTER(A), c_void_p)


class Test(object):
    def __init__(self, path):
        self.dllModule = CDLL(path)
        # self.cb = Callback()
        # self.cb.func = CMPFUNC(self.cb.output_Callback)

        # self.cb = CMPFUNC(cb)
        self.cb = CMPFUNC(self.callback)

    def sub(self):
        self.dllModule.sub(self.cb)

    def call_func1(self):
        # self.dllModule.function1(self.cb.func, c_int(10))
        self.dllModule.function1(self.cb, c_int(10))

    def call_func3(self):
        self.dllModule.function3(c_int(11))

    def callback(self, a, b):
        print(dir(a))
        print(a.contents.a1, a.contents.a2)
        print(b)


if __name__ == "__main__":
    test = Test("xxx\\testDll.dll")
    test.call_func1()

    test.sub()
    test.call_func3()
