damage = 1
b = getCamLoc()

function attack()
	setAn("attaka")
	damagePlayer (damage) 
end


if (getPosX() > b.x - 3  and getPosX() < b.x + 3) and (getPosZ() > b.z - 3 and getPosZ() < b.z + 3 )then
	attack()
end






