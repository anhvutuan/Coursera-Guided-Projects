from flask import Flask, url_for
from datetime import datetime

app = Flask(__name__)
from routes import *

if __name__ == "__main__": app.run(Debug=True)
