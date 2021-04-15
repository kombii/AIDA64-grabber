# use AIDA64-grabber with python

requirements:
ctypes
any xml parser(xml.dom or xml.etree etc.)

## Usage
```Python
import ctypes
dll = ctypes.cdll.LoadLibrary('C:\\AIDA64-grabber-dll.dll')
dll.getData.restype = c_void_p
dll.freebuffer.restype = c_void_p
recv = dll.getData()
if recv is None:
	# do something to handle NULL
	pass
else:
	xmlpointer = cast(recv, c_char_p)
	xmldata = xmlpointer.value.decode(encoding="gbk")# AIDA64 encode in gb2312
	dll.freebuffer(data) # VERY IMPORTANT!! DLL uses malloc to get memory and return 
	# its pointer, which will cause memory leakage. Be sure to pass this pointer back 
	# after reading data to release it
  xmldata = f"<aida64>{xmldata}</aida64>" # Add root node
  # do something to parse xml
	# use it!
```