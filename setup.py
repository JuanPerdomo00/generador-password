#!/usr/bin/python3
# -*- coding: utf-8 -*-

import setuptools

with open("README.md", "r") as fh:
    description = fh.read()

setuptools.setup(
    name="passpyword",
    version="0.1.0",
    script=["gen.py"],
    description="fast password generator for keepass",
    author="Jakepys - JuanPerdomo00",
    author_email="j4kyjak3@protenmail.com",
    long_description=description,
    long_description_content_type="text/markdown",
    license="GPLv3",
    platforms="GNU/Linux",
    url="https://github.com/JuanPerdomo00/generador-password",
    packages=setuptools.find_packages(),
     classifiers=[
         "Programming Language :: Python :: 3",
         "Operating System :: OS Independent",
     ],
     install_requires=["pyperclip3==0.4.1"],
)

