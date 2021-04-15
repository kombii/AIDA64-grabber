from ctypes import cdll, cast
from ctypes import c_char_p, c_void_p
import xmltodict
from xml.dom.minidom import parse
import xml.dom.minidom

dll = cdll.LoadLibrary('C:\\Users\\win10\\Desktop\\cppmmap\\cppmmap\\x64\\Release\\cppmmap.dll')
dll.getData.restype = c_void_p
dll.freebuffer.restype = c_void_p

def find_aimdict_with_id(ele_list:list, id:str):
    for i in range(0,len(ele_list)):
        if ele_list[i]["id"] == id:
            return ele_list[i]
    return None


while 1:
    recv = dll.getData()
    #print(type(recv))
    #print(recv)
    if recv is None:
        print("none???")
        continue
    data = cast(recv, c_char_p)
    aimstr = data.value.decode(encoding="gbk")
    dll.freebuffer(data)
    aimstr = f"<aida64>{aimstr}</aida64>"
    #dict_xml = xmltodict.parse(aimstr)
    dict_xml = xml.dom.minidom.parseString(aimstr)
    #print(dict_xml)
    #cpudict = find_aimdict_with_id(dict_xml["aida64"]["sys"], "SCPUCLK")
    #print(cpudict["value"])




