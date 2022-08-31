#!/usr/bin/python3
# -*- coding: utf-8 -*-
# Copyright (c) 2022 Jakepy Perdomo <j4kyjak3@protonmail.com>.

class Colors:
    def __init__(self):
        self.__off = "\033[0m"
        self.__red = "\033[31m"
        self.__blue = "\033[34m"
        self.__green = "\033[32m"

    @property
    def off(self):
        return self.__off

    @property
    def red(self):
        return self.__red

    @property
    def blue(self):
        return self.__blue

    @property
    def green(self):
        return self.__green

    def __str__(self) -> str:
        return f"Colors"
