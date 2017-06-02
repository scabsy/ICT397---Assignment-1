function faceTarget(targetX,targetZ)
	local xDist =  targetX-getPosX()
	local zDist =  targetZ- getPosZ()
	local angle = math.deg(math.atan(zDist/xDist))
	if getPosX()<targetX then angle=angle + 180 end--else angle=angle end
	return angle-180
end

function chase(targetX,targetZ)
	x = getPosX()
	z = getPosZ()
	setAn("forwrd")
	xDist = targetX - x
	zDist = targetZ - z
	dist = math.sqrt(xDist*xDist+zDist*zDist)
	x = xDist/dist*0.1
	z = zDist/dist*0.1
	setPosX(getPosX() + x)
	setPosZ(getPosZ() + z)
	setRot(-faceTarget(targetX,targetZ))
end

function idle()
	setAn("stand")
end

damage = 0.99

function attack()
	setAn("attaka")
	damagePlayer (damage) 
	setRot(-faceTarget(b.x,b.z))
end

b = getCamLoc()

if (getPosX() > b.x - 256  and getPosX() < b.x + 256) and (getPosZ() > b.z - 256 and getPosZ() < b.z + 256 )then
	
	if (getPosX() > b.x - 15  and getPosX() < b.x + 15) and (getPosZ() > b.z - 15 and getPosZ() < b.z + 15) then
		attack()
		
	else
		chase(b.x,b.z)
	end
else
	idle()
end






