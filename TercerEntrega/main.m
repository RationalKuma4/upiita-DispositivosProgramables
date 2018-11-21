clear all;
close all;
clc;

%% Agregamos ruta de archivos
currentFile = mfilename( 'fullpath' );
[pathstr,~,~] = fileparts( currentFile );
addpath( fullfile( pathstr, 'Audios' ) );
    
% Obtenemos vectores de silabas
[bro,Fs] = audioread('bro.wav');
[fa,Fs] = audioread('fa.wav');
[ma,Fs] = audioread('ma.wav');
[mo,Fs] = audioread('mo.wav');
[pa,Fs] = audioread('pa.wav');
[ro,Fs] = audioread('ro.wav');

%% Normalizamos valores

vectorBro=VectorNormalizado(bro);
vectorFa=VectorNormalizado(fa);
vectorMa=VectorNormalizado(ma);
vectorMo=VectorNormalizado(mo);
vectorPa=VectorNormalizado(pa);
vectorRo=VectorNormalizado(ro);

%% Obtenemos matriz de coeficientes
matrizbro=MatrizMel('bro.wav');
matrizfa=MatrizMel('fa.wav');
matrizma=MatrizMel('ma.wav');
matrizmo=MatrizMel('mo.wav');
matrizpa=MatrizMel('pa.wav');
matrizro=MatrizMel('ro.wav');

%% Escribimos coeficientes
dlmwrite('vbro.txt', vectorBro, 'delimiter', ',', 'precision', 5);
dlmwrite('vfa.txt', vectorFa, 'delimiter', ',', 'precision', 5);
dlmwrite('vma.txt', vectorMa, 'delimiter', ',', 'precision', 5);
dlmwrite('vmo.txt', vectorMo, 'delimiter', ',', 'precision', 5);
dlmwrite('vpo.txt', vectorPa, 'delimiter', ',', 'precision', 5);
dlmwrite('vro.txt', vectorRo, 'delimiter', ',', 'precision', 5);

%% Escribimos matrices
dlmwrite('cbro.txt', matrizbro, 'delimiter', ',', 'precision', 5);
dlmwrite('cfa.txt', matrizfa, 'delimiter', ',', 'precision', 5);
dlmwrite('cma.txt', matrizma, 'delimiter', ',', 'precision', 5);
dlmwrite('cmo.txt', matrizmo, 'delimiter', ',', 'precision', 5);
dlmwrite('cpo.txt', matrizpa, 'delimiter', ',', 'precision', 5);
dlmwrite('cro.txt', matrizro, 'delimiter', ',', 'precision', 5);

%%
[0,6.16837591697061e-05,0.000246719817134200,0.000555062519014993,0.000986635785864221,0.00154133313343602,0.00221901769846000,0.00301952227241015,0.00394264934276106,0.00498817114172123,0.00615582970243112,0.00744533692261307,0.00885637463565564,0.0103885946891171,0.0120416190306263,0.0138150398011617,0.0157084194356845,0.0177212907711010,0.0198531571615285,0.0221034926008349,0.0244717418524232,0.0269573205862274,0.0295596155228873,0.0322779845850663,0.0351117570558743,0.0380602337443566,0.0411226871580094,0.0442983616822774,0.0475864737669902,0.0509862121196922,0.0544967379058161,0.0581171849556533,0.0618466599780682,0.0656842427809044,0.0696289864980282,0.0736799178229539,0.0778360372489925,0.0820963193158649,0.0864597128627191,0.0909251412874883,0.0954915028125263,0.100157670756455,0.104922493812155,0.109784796330835,0.114743378612105,0.119797017199985,0.124944465184770,0.130184452510695,0.135515686289294,0.140936851118406,0.146446609406726,0.152043601703843,0.157726447035656,0.163493743245113,0.169344067338174,0.175275975834908,0.181288005125655,0.187378671832147,0.193546473173512,0.199789887337058,0.206107373853763,0.212497373978361,0.218958311073935,0.225488591000934,0.232086602510502,0.238750717642026,0.245479292124814,0.252270665783796,0.259123162949142,0.266035092869713,0.273004750130227,0.280030415072042,0.287110354217464,0.294242820697446,0.301426054682610,0.308658283817455,0.315937723657661,0.323262578110371,0.330631039877354,0.338041290900925,0.345491502812526,0.352979837383848,0.360504446980385,0.368063475017314,0.375655056417573,0.383277318072047,0.390928379301729,0.398606352321744,0.406309342707138,0.414035449860295,0.421782767479885,0.429549384031209,0.437333383217848,0.445132844454477,0.452945843340743,0.460770452136078,0.468604740235343,0.476446774645179,0.484294620460936,0.492146341344090,0.500000000000000,0.507853658655910,0.515705379539064,0.523553225354821,0.531395259764657,0.539229547863922,0.547054156659257,0.554867155545523,0.562666616782152,0.570450615968791,0.578217232520115,0.585964550139705,0.593690657292862,0.601393647678256,0.609071620698271,0.616722681927953,0.624344943582427,0.631936524982687,0.639495553019615,0.647020162616152,0.654508497187474,0.661958709099075,0.669368960122646,0.676737421889629,0.684062276342339,0.691341716182545,0.698573945317390,0.705757179302554,0.712889645782536,0.719969584927958,0.726995249869773,0.733964907130287,0.740876837050858,0.747729334216204,0.754520707875186,0.761249282357974,0.767913397489499,0.774511408999066,0.781041688926065,0.787502626021639,0.793892626146237,0.800210112662942,0.806453526826488,0.812621328167853,0.818711994874345,0.824724024165092,0.830655932661826,0.836506256754887,0.842273552964344,0.847956398296157,0.853553390593274,0.859063148881594,0.864484313710706,0.869815547489305,0.875055534815230,0.880202982800015,0.885256621387895,0.890215203669165,0.895077506187845,0.899842329243545,0.904508497187474,0.909074858712512,0.913540287137281,0.917903680684135,0.922163962751007,0.926320082177046,0.930371013501972,0.934315757219096,0.938153340021932,0.941882815044347,0.945503262094184,0.949013787880308,0.952413526233010,0.955701638317723,0.958877312841991,0.961939766255643,0.964888242944126,0.967722015414934,0.970440384477113,0.973042679413773,0.975528258147577,0.977896507399165,0.980146842838471,0.982278709228899,0.984291580564316,0.986184960198838,0.987958380969374,0.989611405310883,0.991143625364344,0.992554663077387,0.993844170297569,0.995011828858279,0.996057350657239,0.996980477727590,0.997780982301540,0.998458666866564,0.999013364214136,0.999444937480985,0.999753280182866,0.999938316240830,1,0.999938316240830,0.999753280182866,0.999444937480985,0.999013364214136,0.998458666866564,0.997780982301540,0.996980477727590,0.996057350657239,0.995011828858279,0.993844170297569,0.992554663077387,0.991143625364344,0.989611405310883,0.987958380969374,0.986184960198838,0.984291580564316,0.982278709228899,0.980146842838472,0.977896507399165,0.975528258147577,0.973042679413773,0.970440384477113,0.967722015414934,0.964888242944126,0.961939766255644,0.958877312841991,0.955701638317723,0.952413526233010,0.949013787880308,0.945503262094184,0.941882815044347,0.938153340021932,0.934315757219096,0.930371013501972,0.926320082177046,0.922163962751008,0.917903680684135,0.913540287137281,0.909074858712512,0.904508497187474,0.899842329243545,0.895077506187845,0.890215203669165,0.885256621387895,0.880202982800016,0.875055534815230,0.869815547489305,0.864484313710706,0.859063148881595,0.853553390593274,0.847956398296157,0.842273552964344,0.836506256754887,0.830655932661826,0.824724024165092,0.818711994874345,0.812621328167853,0.806453526826488,0.800210112662942,0.793892626146237,0.787502626021639,0.781041688926065,0.774511408999066,0.767913397489498,0.761249282357974,0.754520707875186,0.747729334216204,0.740876837050858,0.733964907130287,0.726995249869774,0.719969584927958,0.712889645782536,0.705757179302554,0.698573945317390,0.691341716182545,0.684062276342339,0.676737421889629,0.669368960122646,0.661958709099075,0.654508497187474,0.647020162616152,0.639495553019615,0.631936524982686,0.624344943582427,0.616722681927953,0.609071620698271,0.601393647678256,0.593690657292862,0.585964550139705,0.578217232520116,0.570450615968791,0.562666616782152,0.554867155545523,0.547054156659257,0.539229547863922,0.531395259764657,0.523553225354821,0.515705379539064,0.507853658655910,0.500000000000000,0.492146341344090,0.484294620460936,0.476446774645179,0.468604740235344,0.460770452136077,0.452945843340743,0.445132844454477,0.437333383217848,0.429549384031209,0.421782767479885,0.414035449860295,0.406309342707138,0.398606352321744,0.390928379301729,0.383277318072047,0.375655056417573,0.368063475017314,0.360504446980385,0.352979837383848,0.345491502812526,0.338041290900925,0.330631039877355,0.323262578110372,0.315937723657661,0.308658283817455,0.301426054682610,0.294242820697446,0.287110354217464,0.280030415072043,0.273004750130227,0.266035092869713,0.259123162949142,0.252270665783796,0.245479292124814,0.238750717642026,0.232086602510502,0.225488591000935,0.218958311073935,0.212497373978361,0.206107373853764,0.199789887337058,0.193546473173512,0.187378671832147,0.181288005125655,0.175275975834908,0.169344067338174,0.163493743245113,0.157726447035656,0.152043601703843,0.146446609406727,0.140936851118406,0.135515686289294,0.130184452510695,0.124944465184770,0.119797017199985,0.114743378612105,0.109784796330835,0.104922493812155,0.100157670756455,0.0954915028125263,0.0909251412874884,0.0864597128627192,0.0820963193158648,0.0778360372489926,0.0736799178229539,0.0696289864980283,0.0656842427809043,0.0618466599780684,0.0581171849556533,0.0544967379058161,0.0509862121196922,0.0475864737669903,0.0442983616822775,0.0411226871580094,0.0380602337443567,0.0351117570558743,0.0322779845850665,0.0295596155228873,0.0269573205862274,0.0244717418524232,0.0221034926008350,0.0198531571615285,0.0177212907711010,0.0157084194356845,0.0138150398011617,0.0120416190306264,0.0103885946891171,0.00885637463565564,0.00744533692261307,0.00615582970243117,0.00498817114172123,0.00394264934276112,0.00301952227241020,0.00221901769846000,0.00154133313343602,0.000986635785864221,0.000555062519014993,0.000246719817134200,6.16837591697061e-05]
