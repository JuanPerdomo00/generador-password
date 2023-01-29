#!/usr/bin/python3
# -*- coding: utf-8 -*-

from setuptools import setup

setup(
    name="Generador-Password",
    version="0.1.0",
    description="Simple generador contrasenas",
    author="Jakepys - JuanPerdomo00",
    author_email="j4kyjak3@protenmail.com",
    license="GPLv3",
    url="https://github.com/JuanPerdomo00/generador-password",
    py_modules=[i.strip() for i in open("requirements.txt").readlines()]
)
