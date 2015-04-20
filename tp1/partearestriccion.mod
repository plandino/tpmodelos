#Conjuntos: Los sectores de los que se busca el apoyo y los conflictos en los cuales tomar una decision
set SECTORES;
set CONFLICTOS;

#Variables:
#Yi, bivalente que vale 1 si tengo el apoyo del sector i
var Y{i in SECTORES} >= 0, binary;

#Yvi, bivalente que vale 1 si le di la vicepresidencia al sector i
var Yv{i in SECTORES} >=0, binary;

#Yci, bivalente que determina que posicion tuve en el conflicto i
#CONFLICTO Huelga
#Ych vale 1 si estoy a favor de los sindicatos, 			0 si estoy a favor de los empresarios
#Ycd vale 1 si le doy los diputados al sector historico, 	0 si se los doy a la juventud
#Yci vale 1 si estoy a favor de la ley de importaciones, 	0 si estoy en contra de la ley de importaciones
var Yc{i in CONFLICTOS} >=0, binary;

#Funcional:
maximize z: sum{i in SECTORES} Y[i];

#Restricciones:
#Solo se puede otorgar la vicepresidencia a un sector
s.t. vicepresidencia: sum{i in SECTORES} Yv[i]=1;

#Si le doy la vicepresidencia a un sector, si o si tengo su apoyo
s.t. apoyoVicepresidencia{i in SECTORES}: Y[i] >= Yv[i];

#Obtengo el apoyo de los empresarios si apoyo a los empresarios en la huelga(Ych = 0) OR apoyo la ley de importaciones(Yci = 1)
s.t. apoyoEmpresariosMenor: (Y['E'] - Yv['E']) <= (1 - Yc['H']) + Yc['I'];
s.t. apoyoEmpresariosMayor: (1 - Yc['H']) + Yc['I'] <= 2*(Y['E'] - Yv['E']);

#Obtengo el apoyo de los sindicatos, si los apoyo en la huelga (Yc[S] = 1) AND no apoyo la ley de importaciones(Yc[I] = 0)
s.t. apoyoSindicatosMenor: 2*(Y['S'] - Yv['S']) <= Yc['H'] + (1 - Yc['I']);
s.t. apoyoSindicatosMayor: Yc['H'] + (1 - Yc['I']) <= (Y['S'] - Yv['S']) + 1;

#Obtengo el apoyo de la juventud, si le doy los diputados a la juventud (Yc[D] = 0) AND apoyo a los empresarios en la huelga (Yc[H] = 0)
s.t. apoyoJuventudMenor: 2*(Y['J'] - Yv['J']) <= (1 - Yc['D']) + (1 - Yc['H']);
s.t. apoyoJuventudMayor: (1 - Yc['D']) + (1 - Yc['H']) <= (Y['J'] - Yv['J']) + 1;

#Obtengo el apoyo de la corriente historica, si apoyo a los sindicatos en la huelga (Yc[H] = 1) OR le doy los diputados a la 
#corriente historica (Yc[D] = 1) OR no apoyo la ley de importaciones (Yc[I] = 0)
s.t. apoyoHistoricosMenor: (Y['CH'] - Yv['CH']) <= Yc['H'] + Yc['D'] + (1 - Yc['I']);
s.t. apoyoHistoricosMayor: Yc['H'] + Yc['D'] + (1 - Yc['I']) <= 3*(Y['CH'] - Yv['CH']);

#Obtengo el apoyo de como mucho tres sectores
s.t. restriccionTres: sum{i in SECTORES} Y[i] <= 3; 

solve;

#Data segment
data;

set SECTORES:= E S J CH;
set CONFLICTOS:= H D I;

end;