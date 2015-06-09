Problem:    parteb
Rows:       7
Columns:    5
Non-zeros:  13
Status:     OPTIMAL
Objective:  z = 2580000 (MAXimum)

   No.   Row name   St   Activity     Lower bound   Upper bound    Marginal
------ ------------ -- ------------- ------------- ------------- -------------
     1 z            B       2.58e+06                             
     2 minimoTrenesAComprar
                    NL            50            50                       -2000 
     3 viasCubiertas
                    NL             0            -0                         -10 
     4 coberturaTrenes
                    B           4500            -0               
     5 viasTotales  NS         48000         48000             =            10 
     6 trenesTotales
                    NS          1000          1000             =          2000 
     7 presupuesto  NL        -1e+06        -1e+06                        -0.2 

   No. Column name  St   Activity     Lower bound   Upper bound    Marginal
------ ------------ -- ------------- ------------- ------------- -------------
     1 trenes_a_comprar
                    B             50             0               
     2 kms_vias_a_construir
                    B              0             0               
     3 trenes_totales
                    B           1050             0               
     4 kms_vias_totales
                    B          48000             0               
     5 kms_vias_cubiertas
                    B          48000             0               

Karush-Kuhn-Tucker optimality conditions:

KKT.PE: max.abs.err = 0.00e+00 on row 0
        max.rel.err = 0.00e+00 on row 0
        High quality

KKT.PB: max.abs.err = 0.00e+00 on row 0
        max.rel.err = 0.00e+00 on row 0
        High quality

KKT.DE: max.abs.err = 0.00e+00 on column 0
        max.rel.err = 0.00e+00 on column 0
        High quality

KKT.DB: max.abs.err = 0.00e+00 on row 0
        max.rel.err = 0.00e+00 on row 0
        High quality

End of output
