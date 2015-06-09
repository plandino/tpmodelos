#Las constantes que uso en el modelo
param COSTO_MIL_KM_VIAS;
param COSTO_TREN;
param DISTANCIA_TREN;
param KMS_ACTUALES_VIAS;
param TRENES_ACTUALES;
param BENEFICIO_TREN;
param BENEFICIO_KM_VIA_CUBIERTA;
param PRESUPUESTO;
param DISTANCIA_TREN_AV;
param BENEFICIO_TREN_AV;
param COSTO_TREN_AV;

#Variables:
var trenes_a_comprar >= 0;
var kms_vias_a_construir >=0;
var trenes_totales >= 0;
var kms_vias_totales >=0;
var kms_vias_cubiertas >=0;
var trenes_alta_velocidad >=0;

#Funcional:
maximize z: (BENEFICIO_TREN * trenes_totales) + (BENEFICIO_KM_VIA_CUBIERTA * kms_vias_cubiertas) + (BENEFICIO_TREN_AV * trenes_alta_velocidad);

#Restricciones:
#Debo comprar como mínimo 40 trenes
s.t. minimoTrenesAComprar: trenes_a_comprar + trenes_alta_velocidad >= 40;

#Las vias totales deben ser más que las vias cubiertas
s.t. viasCubiertas: kms_vias_totales >= kms_vias_cubiertas;

#Cada tren puede cubrir como maximo 50 kms de vias
s.t. coberturaTrenes: (trenes_totales * DISTANCIA_TREN) + (trenes_alta_velocidad * DISTANCIA_TREN_AV) >= kms_vias_cubiertas;

#Las vias totales son lo que construi mas lo que tenia construido
s.t. viasTotales: kms_vias_totales = kms_vias_a_construir + KMS_ACTUALES_VIAS;

#Los trenes totales son los que ya tenia mas los que compre
s.t. trenesTotales: trenes_totales = trenes_a_comprar + TRENES_ACTUALES;

#Los gastos de compras de trenes y construccion de vias no pueden exceder el presupuesto de 1000 millones
s.t. presupuesto: PRESUPUESTO >= (trenes_a_comprar * COSTO_TREN) + (COSTO_TREN_AV * trenes_alta_velocidad) + (kms_vias_a_construir * (COSTO_MIL_KM_VIAS / 1000));

solve;

#Data segment
data;

#Los precios están en miles
param COSTO_MIL_KM_VIAS := 50000;
param COSTO_TREN := 20000;
param DISTANCIA_TREN := 50;
param KMS_ACTUALES_VIAS := 48000;
param TRENES_ACTUALES := 1000;
param BENEFICIO_TREN :=2000;
param BENEFICIO_KM_VIA_CUBIERTA := 10;
param PRESUPUESTO := 1000000;
param DISTANCIA_TREN_AV := 100;
param BENEFICIO_TREN_AV := 3800;
param COSTO_TREN_AV := 30000;

end;