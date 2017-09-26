# pybluez
import bluetooth

# hledame zarizeni
print "Hledam zarizeni..."
print ""
nearby_devices = bluetooth.discover_devices()

# vyber prvni zarizeni ze seznamu
selection = 0
bd_addr = nearby_devices[selection]

port = 1
sock = bluetooth.BluetoothSocket(bluetooth.RFCOMM)

# odpojeni
def disconnect():
	sock.close()

# posilani dat
def send(data):
	sock.send(data)

# pripoj se k zarizeni        
sock.connect((bd_addr, port))
print 'Spojeno.'
print 'Cekam na prikazy pro Robopixli. Mozne prikazy jsou: F = dopredu, B = dozadu, L = vlevo, R = vpravo.'

# nekonecne opakovani, prerusi se Ctrl+C
while True:
	# nacti znak ze vstupu z klavesnice
	ch = raw_input();
	# posli pres BT
	send(ch)
disconnect()