import time
from coapthon import defines
import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BOARD)
#GPIO.setwarnings(False)
GPIO.setup(3, GPIO.OUT)

from coapthon.resources.resource import Resource

__author__ = 'Giacomo Tanganelli'


class BasicResource(Resource):
    def __init__(self, name="BasicResource", coap_server=None):
        super(BasicResource, self).__init__(name, coap_server, visible=True,
                                            observable=True, allow_children=True)
        self.payload = "Basic Resource"
        self.resource_type = "rt1"
        self.content_type = "text/plain"
        self.interface_type = "if1"

    def render_GET(self, request):
        #self.payload ="45"
        return self

    def render_PUT(self, request):
        self.edit_resource(request)
        return self

    def render_POST(self, request):
        res = self.init_resource(request, BasicResource())
        print request
        return request
       
    def render_DELETE(self, request):
        return True








