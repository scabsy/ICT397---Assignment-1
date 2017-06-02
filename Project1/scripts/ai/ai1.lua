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
	setAn("walk")
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

damage = 0.1

function attack()
	setAn("attak")
	damagePlayer (damage) 
	setRot(-faceTarget(b.x,b.z))
end

b = getCamLoc()

if (getPosX() > b.x - 40  and getPosX() < b.x + 40) and (getPosZ() > b.z - 40 and getPosZ() < b.z + 40 )then
	
	if (getPosX() > b.x - 8  and getPosX() < b.x + 8) and (getPosZ() > b.z - 8 and getPosZ() < b.z + 8) then
		attack()
		
	else
		chase(b.x,b.z)
	end
else
	idle()
end






