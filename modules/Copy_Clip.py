#!/usr/bin/python3
# -*- coding: utf-8 -*-
# Copyright (c) 2022 Jakepy Perdomo <j4kyjak3@protonmail.com>.

from modules.Colors import Colors


class Copy_Clip(Colors):
    def __init__(self):
        self.__password = ""

    @property
    def password(self):
        return self.__password

    def copy_pass(self, arg_password):
        import pyperclip3 as c
        """
        Import pyperclip3
        return copy password to clipboard
        """
        self.__password = arg_password
        copy = c.copy(self.__password)
        paste = c.paste(copy)
        print(f"\n{Colors().green}[+] Password copied to clipboard {Colors().off}")
        return paste
