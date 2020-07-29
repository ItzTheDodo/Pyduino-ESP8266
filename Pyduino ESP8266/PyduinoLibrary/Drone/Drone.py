import urllib.request
import time


class PyduinoDrone(object):

    def __init__(self, ip, url):
        self.ip = ip
        self.url = url

    def up(self):
        n = urllib.request.urlopen(self.url + "/up")
        return n

    def down(self):
        n = urllib.request.urlopen(self.url + "/down")
        return n

    def right(self):
        n = urllib.request.urlopen(self.url + "/right")
        return n

    def left(self):
        n = urllib.request.urlopen(self.url + "/left")
        return n

    def forward(self):
        n = urllib.request.urlopen(self.url + "/forward")
        return n

    def backward(self):
        n = urllib.request.urlopen(self.url + "/backward")
        return n

    def getLatLong(self):
        urllib.request.urlopen(self.url + "/dist")
        time.sleep(1)
        n = urllib.request.urlopen(self.url + "/dist")
        return n
