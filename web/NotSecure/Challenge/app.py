#!/usr/bin/env python3
from flask import Flask, render_template, request, make_response, redirect
import os
import random


app = Flask(__name__, template_folder='./static')


secret = "wiwikiki"
flagy = os.environ.get(
    'FLAG', 'DEFENSYS{ins3cUr3__s3cr3t5_4r3_Dangerous_31338}')


def create_jwt(username, password, alg='HS256'):
    import jwt
    import datetime

    payload = {
        'username': username,
        'password': password,
        'exp': datetime.datetime.utcnow() + datetime.timedelta(seconds=60)
    }
    token = jwt.encode(payload, secret, algorithm=alg)
    return token


def verify_jwt(token, alg):
    import jwt
    try:
        payload = jwt.decode(token, secret, algorithms=alg)
        print(payload)
        return payload.get('username')
    except jwt.ExpiredSignatureError:
        return 'Token expired'
    except jwt.InvalidTokenError:
        return 'Invalid token'


@app.route('/')
def index():
    if request.args.get('username') and request.args.get('password'):
        if len(request.args.get('username')) < 10:
            return render_template('index.html', error='Username too short (should not be less than 10)')
        username = request.args.get('username')
        password = request.args.get('password')
        if username == "admin":
            return render_template('index.html', error='you cant use admin as a username')
        token = create_jwt(username, password)
        r = make_response(redirect('/flag'))
        r.set_cookie('token', token)
        return r
    else:
        return render_template('index.html', error='Signup UnderConstruct|Admins can login')


@app.route('/flag')
def flag():
    token = request.cookies.get('token')
    if token:
        username = verify_jwt(token, alg='HS256')
        print(username)
        if username == 'admin':
            return render_template('flag.html', flag=flagy)
        else:
            return render_template('flag.html', flag=f"Not an admin")


if __name__ == '__main__':
    app.run()
