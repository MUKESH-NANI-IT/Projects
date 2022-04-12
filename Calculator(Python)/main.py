import tkinter as tk
from tkinter import *

root = tk.Tk()
root.iconphoto(False, tk.PhotoImage(file="resources\calculator-icon (1).png "))


def calc(source, side):
    storeObj = Frame(source, borderwidth=4, bd=4, bg="black")
    storeObj.pack(side=side, expand=YES, fill=BOTH)
    return storeObj


def button(source, side, text, command=None):
    storeObj = Button(source, text=text, command=command)
    storeObj.pack(side=side, expand=YES, fill=BOTH)
    return storeObj


class app(Frame):
    def __init__(self):
        global btniEquals
        Frame.__init__(self)
        self.option_add('*Font', 'arial 20 bold')
        self.pack(expand=YES, fill=BOTH)
        self.master.title('Calculator')

        display = StringVar()
        Entry(self, relief=RIDGE, textvariable=display,
              justify='right'
              , bd=30, bg="pink").pack(side=TOP,
                                       expand=YES, fill=BOTH)

        for clearButton in (["C"]):
            erase = calc(self, TOP)
            for ichar in clearButton:
                button(erase, LEFT, ichar, lambda
                    storeObj=display, q=ichar: storeObj.set(''))

        for numButton in ("789/", "456*", "123-", "0.+"):
            FunctionNum = calc(self, TOP)
            for iEquals in numButton:
                button(FunctionNum, LEFT, iEquals, lambda
                    storeObj=display, q=iEquals: storeObj
                       .set(storeObj.get() + q))

        EqualButton = calc(self, TOP)
        for iEquals in "=":
            if iEquals == '=':
                btniEquals = button(EqualButton, LEFT, iEquals,
                                    lambda storeObj=display, s=' %s ' % iEquals: storeObj.set(storeObj.get()))


        else:
            # btniEquals = button(EqualButton, LEFT, iEquals)
            btniEquals.bind('<ButtonRelease-1>', lambda e, s=self, storeObj=display: s.calc(storeObj), '+')

    def calc(self, display):
        try:
            display.set(eval(display.get()))
        except:
            display.set("ERROR")


if __name__ == '__main__':
    app().mainloop()
