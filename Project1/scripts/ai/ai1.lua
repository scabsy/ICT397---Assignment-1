
b = getCamLoc()

x = getPosX()
z = getPosZ()

xDist = b.x - x
zDist = b.z - z
dist = math.sqrt(xDist*xDist+zDist*zDist)
x = xDist/dist*0.1
z = zDist/dist*0.1
setPosX(getPosX() + x)
setPosZ(getPosZ() + z)

xDist = b.x - getPosX()
zDist = b.z - getPosZ()

rot = math.rad(math.atan(zDist/xDist))

if rot < 0 then
	rot = math.abs(rot)
else
	rot = 2 * math.pi - rot
end

setRot(math.deg(rot))

