from Drone import PyduinoDrone
import urllib.request


class Pyduino(object):

    def __init__(self, ip):
        self.ip = ip
        self.url = "https://" + self.ip
        self.isDrone = False

    def bind(self, ip):
        self.ip = ip
        self.url = "https://" + self.ip

    def setupForDrone(self):
        self.isDrone = True

        return PyduinoDrone(self.ip, self.url)

    def sendRequestCustomUrl(self, urlEnd):
        n = urllib.request.urlopen(self.url + "/" + urlEnd)
        return n

    def setPinHigh(self, pin):
        if int(pin) > 13:
            return None
        n = urllib.request.urlopen(self.url + "/High:" + str(pin))
        return n

    def setPinLow(self, pin):
        if int(pin) > 13:
            return None
        n = urllib.request.urlopen(self.url + "/Low:" + str(pin))
        return n

    def setOutput(self, pin):
        if int(pin) > 13:
            return None
        n = urllib.request.urlopen(self.url + "/out:" + str(pin))
        return n

    def setInput(self, pin):
        if int(pin) > 13:
            return None
        n = urllib.request.urlopen(self.url + "/in:" + str(pin))
        return n

    def getInfoCustomUrl(self, urlEnd):
        n = urllib.request.urlopen(self.url + "/" + urlEnd)
        return n
