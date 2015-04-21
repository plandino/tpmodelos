Problem:    partea
Rows:       15
Columns:    11 (11 integer, 11 binary)
Non-zeros:  50
Status:     INTEGER OPTIMAL
Objective:  z = 4 (MAXimum)

   No.   Row name        Activity     Lower bound   Upper bound
------ ------------    ------------- ------------- -------------
     1 z                           4                             
     2 vicepresidencia
                                   1                           1 
     3 apoyoVicepresidencia[CH]
                                   1            -0               
     4 apoyoVicepresidencia[S]
                                   0            -0               
     5 apoyoVicepresidencia[J]
                                   1            -0               
     6 apoyoVicepresidencia[E]
                                   1            -0               
     7 apoyoHistoricosMenor
                                   1                           1 
     8 apoyoHistoricosMayor
                                  -3                          -1 
     9 apoyoJuventudMenor
                                   2                           2 
    10 apoyoJuventudMayor
                                  -1                          -1 
    11 apoyoEmpresariosMenor
                                   1                           1 
    12 apoyoEmpresariosMayor
                                  -2                          -1 
    13 apoyoSindicatosMenor
                                   0                           1 
    14 apoyoSindicatosMayor
                                  -1                          -0 
    15 apoyoCuatroSectores
                                   4             4             = 

   No. Column name       Activity     Lower bound   Upper bound
------ ------------    ------------- ------------- -------------
     1 Y[CH]        *              1             0             1 
     2 Y[S]         *              1             0             1 
     3 Y[J]         *              1             0             1 
     4 Y[E]         *              1             0             1 
     5 Yv[CH]       *              0             0             1 
     6 Yv[S]        *              1             0             1 
     7 Yv[J]        *              0             0             1 
     8 Yv[E]        *              0             0             1 
     9 Yc[I]        *              0             0             1 
    10 Yc[D]        *              0             0             1 
    11 Yc[H]        *              0             0             1 

Integer feasibility conditions:

KKT.PE: max.abs.err = 0.00e+00 on row 0
        max.rel.err = 0.00e+00 on row 0
        High quality

KKT.PB: max.abs.err = 0.00e+00 on row 0
        max.rel.err = 0.00e+00 on row 0
        High quality

End of output
