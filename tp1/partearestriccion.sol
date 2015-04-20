Problem:    partearestriccion
Rows:       15
Columns:    11 (11 integer, 11 binary)
Non-zeros:  54
Status:     INTEGER OPTIMAL
Objective:  z = 3 (MAXimum)

   No.   Row name        Activity     Lower bound   Upper bound
------ ------------    ------------- ------------- -------------
     1 z                           3                             
     2 vicepresidencia
                                   1             1             = 
     3 apoyoVicepresidencia[E]
                                   1            -0               
     4 apoyoVicepresidencia[S]
                                   0            -0               
     5 apoyoVicepresidencia[J]
                                   0            -0               
     6 apoyoVicepresidencia[CH]
                                   1            -0               
     7 apoyoEmpresariosMenor
                                   1                           1 
     8 apoyoEmpresariosMayor
                                  -2                          -1 
     9 apoyoSindicatosMenor
                                   0                           1 
    10 apoyoSindicatosMayor
                                   0                          -0 
    11 apoyoJuventudMenor
                                   1                           2 
    12 apoyoJuventudMayor
                                  -1                          -1 
    13 apoyoHistoricosMenor
                                   0                           1 
    14 apoyoHistoricosMayor
                                  -2                          -1 
    15 restriccionTres
                                   3                           3 

   No. Column name       Activity     Lower bound   Upper bound
------ ------------    ------------- ------------- -------------
     1 Y[E]         *              1             0             1 
     2 Y[S]         *              1             0             1 
     3 Y[J]         *              0             0             1 
     4 Y[CH]        *              1             0             1 
     5 Yv[E]        *              0             0             1 
     6 Yv[S]        *              1             0             1 
     7 Yv[J]        *              0             0             1 
     8 Yv[CH]       *              0             0             1 
     9 Yc[I]        *              0             0             1 
    10 Yc[H]        *              0             0             1 
    11 Yc[D]        *              1             0             1 

Integer feasibility conditions:

KKT.PE: max.abs.err = 0.00e+00 on row 0
        max.rel.err = 0.00e+00 on row 0
        High quality

KKT.PB: max.abs.err = 0.00e+00 on row 0
        max.rel.err = 0.00e+00 on row 0
        High quality

End of output
