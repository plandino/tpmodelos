# Conjuntos: Los sectores de los que se busca el apoyo y los conflictos en los cuales tomar una decision
set SECTORES;
set CONFLICTOS;


# Variables:
# Yi, bivalente que vale 1 si Frank tiene el apoyo del sector i
var Y{i in SECTORES} >= 0, binary;

# Yvi, bivalente que vale 1 si Frank le dio la vicepresidencia al sector i
var Yv{i in SECTORES} >=0, binary;

# Yci, bivalente que determina que posicion tuvo Frank en el conflicto i
# CONFLICTO Huelga
# Ych vale 1 si se esta a favor de los sindicatos, 			0 si esta a favor de los empresarios
# CONFLICTO Diputados
# Ycd vale 1 si se dan los diputados al sector historico, 	0 si se los da a la juventud
# CONFLICTO Importaciones
# Yci vale 1 si esta a favor de la ley de importaciones, 	0 si esta en contra de la ley de importaciones
var Yc{i in CONFLICTOS} >=0, binary;


# Funcional:
maximize z: sum{i in SECTORES} Y[i];


# Restricciones:
# Solo se puede otorgar la vicepresidencia a un sector
s.t. vicepresidencia: sum{i in SECTORES} Yv[i] <= 1;

# Si se le da la vicepresidencia a un sector, si o si tengo su apoyo
s.t. apoyoVicepresidencia{i in SECTORES}: Y[i] >= Yv[i];

# Se obtiene el apoyo de la corriente historica, si Frank apoya a los sindicatos en la huelga (Yc[H] = 1) OR le da los diputados a la 
# corriente historica (Yc[D] = 1) OR no apoya la ley de importaciones (Yc[I] = 0)
s.t. apoyoHistoricosMenor: (Y['CH'] - Yv['CH']) <= Yc['H'] + Yc['D'] + (1 - Yc['I']);
s.t. apoyoHistoricosMayor: Yc['H'] + Yc['D'] + (1 - Yc['I']) <= 3*Y['CH'];

# Se obtiene el apoyo de la juventud, si Frank le da los diputados a la juventud (Yc[D] = 0) AND apoya a los empresarios en la huelga (Yc[H] = 0)
s.t. apoyoJuventudMenor: 2*(Y['J'] - Yv['J']) <= (1 - Yc['H']) + (1 - Yc['D']);
s.t. apoyoJuventudMayor: (1 - Yc['H']) + (1 - Yc['D']) <= Y['J'] + 1;

# Se obtiene el apoyo de los empresarios si Frank apoya a los empresarios en la huelga (Ych = 0) OR apoya la ley de importaciones (Yci = 1)
s.t. apoyoEmpresariosMenor: (Y['E'] - Yv['E']) <= (1 - Yc['H']) + Yc['I'];
s.t. apoyoEmpresariosMayor: (1 - Yc['H']) + Yc['I'] <= 2*Y['E'];

# Se obtiene el apoyo de los sindicatos, si Frank los apoya en la huelga (Yc[H] = 1) AND no apoya la ley de importaciones (Yc[I] = 0)
s.t. apoyoSindicatosMenor: 2*(Y['S'] - Yv['S']) <= Yc['H'] + (1 - Yc['I']);
s.t. apoyoSindicatosMayor: Yc['H'] + (1 - Yc['I']) <= Y['S'] + 1;

# Se debe obtener el apoyo de los 4 sectores
s.t. apoyoCuatroSectores: sum{i in SECTORES} Y[i] = 4;

solve;


# Data segment
data;

# CH = Corriente Historica, S = Sindicatos, J = Juventud, E = Empresarios
set SECTORES:= CH S J E;
# H = Huelga, D = diputados, I = importaciones
set CONFLICTOS:= H D I;

end;