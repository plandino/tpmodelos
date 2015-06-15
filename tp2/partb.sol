Problem:    parteb
Rows:       7
Columns:    5
Non-zeros:  13
Status:     OPTIMAL
Objective:  z = 2600000 (MAXimum)

   No.   Row name   St   Activity     Lower bound   Upper bound    Marginal
------ ------------ -- ------------- ------------- ------------- -------------
     1 z            B        2.6e+06                             
     2 minimoTrenesAComprar
                    B             40            39               
     3 viasCubiertas
                    NL             0            -0                    -5.55556 
     4 coberturaTrenes
                    NL             0            -0                    -4.44444 
     5 viasTotales  NS         48000         48000             =       5.55556 
     6 trenesTotales
                    NS          1000          1000             =       2222.22 
     7 presupuesto  NL        -1e+06        -1e+06                   -0.111111 

   No. Column name  St   Activity     Lower bound   Upper bound    Marginal
------ ------------ -- ------------- ------------- ------------- -------------
     1 trenes_a_comprar
                    B             40             0               
     2 kms_vias_a_construir
                    B           4000             0               
     3 trenes_totales
                    B           1040             0               
     4 kms_vias_totales
                    B          52000             0               
     5 kms_vias_cubiertas
                    B          52000             0               

Karush-Kuhn-Tucker optimality conditions:

KKT.PE: max.abs.err = 1.48e-10 on row 7
        max.rel.err = 7.39e-17 on row 7
        High quality

KKT.PB: max.abs.err = 0.00e+00 on row 0
        max.rel.err = 0.00e+00 on row 0
        High quality

KKT.DE: max.abs.err = 2.05e-13 on column 1
        max.rel.err = 4.61e-17 on column 1
        High quality

KKT.DB: max.abs.err = 0.00e+00 on row 0
        max.rel.err = 0.00e+00 on row 0
        High quality

End of output
