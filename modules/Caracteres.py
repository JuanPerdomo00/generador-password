#!/usr/bin/python3
# -*- coding: utf-8 -*-
# Copyright (c) 2022 Jakepy Perdomo <j4kyjak3@protonmail.com>.

import string

# MAYUS = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'Ñ', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'X', 'Y', 'Z']
# MINUS = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'ñ', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'x', 'y', 'z']
# NUMS =  ['1', '2', '3', '4', '5', '6', '7', '8', '9', '0']
# CHARS = ['*', '+', '-', '/', '@', '_', '?', '!', '(', '[', '{', ')', '}', ']', ',', ';', '.', '>', '<', '~', '°', '^', '&', '$', '#', '"']


class Caracteres:
    def __init__(self):
        self.__MAYUS = string.ascii_uppercase
        self.__MINUS = string.ascii_lowercase
        self.__NUMS = string.punctuation
        self.__CHARS = string.digits

    @property
    def mayus(self):
        """return: self.__MAYUS"""
        return self.__MAYUS

    @property
    def minus(self):
        """return: self.__MINUS"""
        return self.__MINUS

    @property
    def nums(self):
        """return: self.__NUMS"""
        return self.__NUMS

    @property
    def char(self):
        """return: self.__CHARS"""
        return self.__CHARS

    def __str__(self) -> str:
        """return str -> self"""
        return f"{self.mayus}, {self.minus}, {self.char}, {self.nums}"
