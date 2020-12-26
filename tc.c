char code linery_no[14] = {18,  20,  19,  32,  22,  24,  19,  24,  28,  17,  17,  18,    3,    3};
		        /*  {S,   R,   B,   K,   N,   E,   J,   T,   W,   L,   U,  Pt100, Cu50, Cu100}  */

float code tc_s_mv[19] = {
       0.1697787,    0.3884172,    0.6672541,   1.0214492,    1.4704441,    2.0408241,
	   2.7642332,    3.6643625,    4.7120702,   5.8245548,    6.9516306,    8.1132384,
	   9.3580914,   10.7044909,   12.5221605,  15.8701339,   17.4634788,   18.2221526,   18.6092699};
float code tc_s_k[19]  = {
	 173.6586268,  155.4304687,  141.2379050,  130.1011009,  121.3371691,  114.4471898,
	 109.0368479,  104.7430968,  101.1662968,   97.8903673,   94.6716544,   91.5091372,
	  88.5191802,   85.7749186,   83.4874020,   82.5348825,   84.2671622,   86.8828273,  92.1788901};
float code tc_s_b[19]  = {
	   0.2997585,    3.4106493,    8.9398943,  16.3891246,    25.3598091,   35.5116149,
	  46.5745925,   58.4656062,   71.5895455,  87.0333416,   105.7788555,  127.7620333,
	 152.0223641,  177.7104472,  202.2095967,  213.8594582,  186.4010751,  140.8053142,  44.4309258};

float code tc_r_mv[21] = {
	  0.1567131,    0.3580408,    0.6139148,   0.9351022,    1.3345805,    1.8286912,
	  2.4356577,    3.1716017,    4.0408148,   5.0225843,    6.0784489,    7.1873432,
	  8.3550085,    9.6072909,   10.9743043,  12.5311030,   14.6878609,   18.3309470,
	  20.0676411,  20.8095982,   21.0026408};
float code tc_r_k[21]  = {
	  176.6561118,  156.8806906,  141.4140668, 129.1577985,   119.3643428,  111.4791753,
	  105.0849911,   99.8505966,   95.4751552,  91.6650232,    88.1724419,   84.8583237,
	  81.6990697,    78.7319666,   75.9997473,  73.5324143,    71.6105173,   70.9196390,
	  72.4048434,    75.5443742,   79.2512307};
float code tc_r_b[21]  = {
	  0.2998184,      3.4134309,    8.9676531,  16.5077937,     25.6813919,   36.2215685,
	 47.9317475,     60.6976977,   74.5904408,  89.9985730,    107.5459960,  127.6925546,
	150.4001698,    175.1936186,  201.4482553, 228.5326861,    252.6409834,  262.4753551,
	235.3039599,    172.3496123,   95.4813388};

float code tc_b_mv[20] = {
	   0.9534123,    1.1459563,    1.3664640,    1.6183674,     1.9048030,     2.2333802,
	   2.5965310,    3.0009060,    3.4529156,    3.9594712,     4.5263381,     5.1586835,
	   5.8618092,    6.6460943,    7.5276213,    8.5426568,     9.7786047,    11.6982812,
	  13.5626002,   13.8202792};
float code tc_b_k[20]  = {
	 234.8607062,  214.9827591,  197.6972133,  182.5849965,   169.3008341,   157.6320199,
	 147.3099237,  137.9768734,  129.6293288,  122.1847999,   115.5356355,   109.5814128,
	 104.2388957,   99.4435263,   95.1642984,   91.4107467,    88.2506959,    85.8992102,
	  85.9297668,   87.3167587};
float code tc_b_b[20]  = {
	 215.5735289,  234.5323281,  254.3464456,  275.0036929,   296.5090319,   318.7414022,
	 341.7999084,  366.0384978,  391.0938237,  416.8057239,   443.1398287,   470.0974465,
	 497.6639455,  525.7808598,  554.2285926,  582.4944014,   609.5042174,   632.5253963,
	 631.7678919,  613.2471261};

float code tc_k_mv[33] = {
	  -5.7245923,   -5.5229111,   -5.2823988,  -4.9990649,     -4.6664659,    -4.2788579,
	  -3.8303824,   -3.3105351,   -2.7079030,  -2.0070433,     -1.1879611,    -0.2162107, 
	   1.0793205,    2.9363794,    5.1816066,   7.1403851,      9.6802950,    11.9187339, 
	  14.9582770,   18.9302672,   26.1023806,  29.6374430,     32.7004299,    35.5741665,
	  38.3487243,   41.0239577,   43.5471538,  45.8732904,     48.0023603,    49.9658831, 
	  51.8176724,   53.6182527,   54.8185689};
float code tc_k_k[33]  = {
	  61.7275138,   55.2704949,   49.8816725,  45.3431640,     41.4831565,    38.1757094, 
	  35.3355601,   32.8883767,   30.7760330,  28.9590500,     27.4036484,    26.0801139,   
      25.0414962,   24.2717792,   24.1906810,  24.8206177,     24.9579972,    24.4109279,
	  23.9637227,   23.6375429,   23.4728089,  23.7453623,     24.1093981,    24.5147129, 
	  24.9407086,   25.3805750,   25.8394421,  26.3300599,     26.8649374,    27.4496130, 
	  28.0804403,   28.7412569,   29.2848354};
float code tc_k_b[33]  = { 
	 163.7613079,  126.8009816,   97.0419685,  73.0701716,     53.7768975,    38.3456183,
	  26.1952603,   16.8247109,    9.8348727,   4.9180300,      1.8001032,     0.2320908,
	   0.0139960,    0.8528464,    0.9528962,  -2.3105677,     -3.1502415,     2.1449652,
	   7.4827188,   12.3730807,   15.4035461,   8.2978095,     -2.4880649,   -15.7408296, 
	 -30.8946986,  -47.7620756,  -66.5846138, -87.9468679,   -112.4808772,  -140.5445696,
	-172.0634868, -206.3048898, -235.3940703};

float code tc_n_mv[23] = {
	  -0.6303934,    0.3187511,    1.1192869,   1.9447597,      2.8216017,     3.7724408,
	   4.8185724,    5.9761499,    7.2686825,   8.7174218,     10.3442654,    12.1825177,
	  14.2813013,   16.7287206,   19.7261650,  23.9576015,     31.7227649,    35.8227694,
	  39.1577902,   42.1154455,   44.7768945,  46.9852892,     47.5127720};
float code tc_n_k[23]  = {
	  40.1002883,   38.5351081,   37.2265936,  35.7365402,     34.3261358,    33.0213159, 
	  31.8291413,   30.7513820,   29.7840084,  28.9193183,     28.1504141,    27.4695511,
	  26.8704653,   26.3518093,   25.9190287,  25.5895265,     25.4758392,    25.7046672,
	  26.0251093,   26.4049163,   26.8258977,  27.3010696,     27.6781842};
float code tc_n_b[23]  = {
	   0.9704801,   -0.0080420,    0.4334966,   2.1004408,      4.8434687,     8.5265326,
	  13.0263250,   18.2218287,   24.0061502,  30.2945980,     37.0006289,    44.0473476,
	  51.3499037,   58.7617746,   66.0077770,  72.5167584,     75.1355625,    67.8871706,
	  56.4137417,   41.5446595,   23.8190459,   2.5503131,    -15.0751397};

float code tc_e_mv[25] = {
	  -8.5248624,   -8.1643266,   -7.7366994,  -7.2357234,     -6.6513838,    -5.9768870, 
	  -5.2055222,   -4.3260371,   -3.3267017,  -2.1900435,     -0.9136472,     0.5733160,
	   2.2828361,    4.1226768,    6.1369088,   8.3792499,     10.9136636,    13.8217857,
	  17.2110641,   21.2310977,   26.1142777,  32.4488030,     47.2038873,    54.5997893,  61.0095287};
float code tc_e_k[25]  = {
	  37.6906815,   34.1072439,   31.0949440,  28.5385582,     26.3497775,    24.4587705,
	  22.8133759,   21.3731221,   20.1106226,  19.0007112,     18.0177675,    17.1429018,
	  16.4368904,   15.7613080,   15.1410311,  14.5815676,     14.0845765,    13.6498464,
	  13.2755912,   12.9585575,   12.6950802,  12.4850720,     12.3663789,    12.5062655,  12.6679852};
float code tc_e_b[25]  = {
	 132.7033241,  102.1587576,   77.5687370,  57.7934498,     41.9593658,    29.3843906,
	  19.5524893,   12.0578404,    6.5985380,   2.9093891,      0.7592832,    -0.0379851,
	   0.3760169,    1.9194375,    4.4782637,   7.9141164,     12.0816913,    16.8300109,
	  22.0073796,   27.4692401,   33.0694313,  38.5612350,     42.3586041,    35.7598970,  26.9463519};

float code tc_j_mv[20] = {
	  -7.4899999,   -6.9899999,   -6.3899999,  -5.5899999,     -4.5899999,    -3.2899999,
	  -1.7899999,    0.3100001,    3.1100001,   6.8100001,     21.2100001,    28.0100001,
	  32.4100001,   36.1100001,   39.9100001,  44.7100001,     50.5100001,    54.6100001,
	  58.9100001,   63.7100001};
float code tc_j_k[20] = {
	  41.7481178,   35.5100486,   31.1941281,  27.9987211,     25.3244083,    23.1833371,
	  21.5812226,   20.2606144,   19.1968356,  18.4630258,     18.0517297,    18.0311844,
	  17.5345751,   16.9067440,   16.2565142,  15.7093961,     15.5573010,    16.1248568,
	  16.7181744,   17.1636536};
float code tc_j_b[20]  = {
	 129.6807334,   82.9609612,   52.7771856,  32.3919815,     17.4661951,     7.6552781,
	   2.3873935,    0.0500117,    0.3629715,   2.6549112,      5.3649670,     6.1581186,
	  20.0453371,   40.3664565,   63.8482087,  85.6934156,     92.1908784,    63.5456848,
	  31.1483679,    4.9518141};

float code tc_t_mv[25] = {
	  -5.4050114,   -5.1725395,   -4.9030966,  -4.5922692,     -4.2375142,    -3.8364143,
	  -3.3814209,   -2.8657033,   -2.2864756,  -1.6362401,     -0.9072847,    -0.0946687,
	   0.8864870,    1.8863729,    2.9712512,   4.1804310,      5.5334087,     7.0339662,
	   8.6780334,   10.4790124,   12.4641822,  14.6675756,     17.0728074,    19.6774712,  20.8688798};
float code tc_t_k[25] = {
	  60.3557093,   54.8351450,   50.0948146,  45.9995001,     42.4183780,    39.2621459,
	  36.4792401,   34.0262273,   31.8493819,  29.9086178,     28.1886376,    26.6378709,
	  25.3300578,   24.1021976,   22.9498731,  21.9134344,     20.9888139,    20.1576890,
	  19.4018496,   18.7107460,   18.0826839,  17.5172131,     17.0039144,    16.5263626,  16.2400933};
float code tc_t_b[25]  = {
	 138.2700370,  108.4344072,   83.9168443,  63.8396732,     47.3965477,    34.0235110,
	  23.3492076,   15.0569029,    8.8207874,   4.3851511,      1.5729578,     0.1680499,
	   0.0461249,    1.1335786,    3.3077086,   6.3893772,     10.2574894,    14.8592373,
	  20.1778831,   26.1775179,   32.7611188,  39.8121231,     47.3436935,    55.4985171,  61.0501401};

float code tc_w_mv[29] = {
	   0.3061727,    0.6848393,    1.1477284,   1.7098665,      2.3903064,     3.2109345,
	   4.2066154,    5.4252551,    6.9567383,   8.9953223,     12.4005670,    16.8372686,
	  19.6277877,   22.0698372,   24.3146888,  26.4071682,     28.3538924,    30.1405606,
	  31.7525478,   33.1832160,   34.4364889,  35.5243711,     36.4631271,    37.2698720,
	  37.9609523,   38.5506490,   39.0513574,  39.4747326,     39.5002855};
float code tc_w_k[29]  = {
	  98.2723719,   87.9091340,   79.4749103,  72.5580462,     66.8492401,    62.1302520,
	  58.2355342,   55.0459462,   52.4823606,  50.5075455,     49.1607861,    48.9585991,
	  50.0552983,   51.4284955,   52.9632291,  54.6220471,     56.3997485,    58.3169721,
	  60.4168591,   62.7606822,   65.4197858,  68.4711192,     71.9979589,    76.0943229,
	  80.8718277,   86.4667142,   93.0467850, 100.8310430,    105.6630582};
float code tc_w_b[29]  = {
	   0.2982672,    3.4838192,    9.2713754,  17.2221198,     26.9965469,   38.2887298,
	  50.8093741,   64.2422419,   78.1697860,  91.9318894,    104.0827972,  106.2698706,
	  87.8240733,   60.8804190,   27.0141158, -13.3149597,    -60.2539325, -114.6075239,
	-177.8906301, -252.3031204, -340.5299357,-445.5957341,   -570.8729241, -720.2277434,
        -898.2738314,-1110.6504298,-1364.3058520,-1668.2821806, -1858.7222386};

float code tc_l_mv[18] = {
	      -6.93,       -5.90,         -4.76,       -2.51,          -1.53,         0.00,  
           2.38,        6.19,         14.59,       20.48,          25.00,        28.72, 
          34.26,       38.16,	      41.26,       45.22,          48.25,        53.14};
float code tc_l_k[18]  = {
	      33.01759338, 29.26291656,   26.25281520,  22.2335166,     20.39157480, 19.4266624,
          18.9849052,  18.42657089,   17.85716056, 17.85804176,    17.706781387,17.54617980,
          17.1643676,  16.6604995,    15.889987,   15.33212852,    14.8629388,  14.285776138};
float code tc_l_b[18]  = {
	      69.19510205, 42.85747196,   25.02454428,  6.104389056,   1.289793978,-0.242225748,
           0.0,         1.20572777,    4.46417614,  4.35851933,     7.62943004, 11.44017050,
          22.11553433, 39.49546673,   68.8509900,  91.90806660,   112.9672433, 141.0423564};

float code tc_u_mv[18] = {
	      -5.02,       -4.46,         -3.54,       -2.96,          -2.02,        -1.14, 
            0.0,        1.21,          3.57,        5.89,           7.89,        10.29, 
          13.13,       16.70,         21.62,       25.76,           29.77,       34.31};
float code tc_u_k[18]  = {
	      51.186397,   45.2436065,    38.00475692, 35.9581871,      32.123977,   29.0719585,
          26.7863216,  25.12593,      23.21186,    21.4812698,      19.98177909, 18.74239730,
          17.6752605,  16.8356037,    16.29991149, 15.68800544,     14.9994573,  14.33872699};
float code tc_u_b[18]  = {
	       91.9638799,  62.04938783,   29.79931166, 21.85622193,     10.18291922,  3.4714957,
          0.379492924,  0.0,            2.22847540,  8.70764921,     17.57621146, 27.36921991,
         38.20918536,   49.13986862,   57.89218612, 71.05795779,     88.69051800,108.2796521};

float code Pt100_r[19] = {
	  30.2406639,  42.6784812,    56.0534248,  70.6546988,      86.6634828,  103.9412192,
	 121.3002486, 138.3131591,   154.9845816, 171.3191161,     187.3213311,  202.9957639,
	 218.3469209, 233.3792771,   248.0972763, 262.5053312,     276.6078234,  290.4091031,   297.4559110};
float code Pt100_k[19] = {
	   2.3389712,   2.3880160,     2.4338003,   2.4759569,       2.5143708,    2.5495899,
	   2.5836621,   2.6185916,     2.6542344,   2.6906101,       2.7277388,    2.7656414,
	   2.8043398,   2.8438562,     2.8842139,   2.9254370,       2.9675504,    3.0105799,     3.0439285};
float code Pt100_b[19] = {
	-243.3804799,-244.8651514,  -246.8207981,-249.1858620,    -251.9019909, -254.9562436,
	-258.4988853,-262.7357136,  -267.6654484,-273.3029749,    -279.6636918, -286.7635334,
	-294.6189912,-303.2471384,  -312.6656538,-322.8928483,    -333.9476924, -345.8498442,  -355.4979918};

float code Cu50_r[4] = {
	  48.7236349,  63.6491310,    77.1410414,  82.1301460};
float code Cu50_k[4]= {
	   4.6466444,   4.6721890,     4.6699964,  4.6502037};
float code Cu50_b[4] = {
	-232.3739883,-233.6210254,  -233.4483160,-231.9405126};

float code Cu100_r[4] = {
	  97.4472698, 127.2982619,   154.2820827, 164.2602920};
float code Cu100_k[4] = {
	   2.3233222,   2.3360945,     2.3349982,   2.3251019};
float code Cu100_b[4] = {
	-232.3739883,-233.6210254,  -233.4483160,-231.9405126};

float code * x_ad[14]= {
       tc_s_mv,   tc_r_mv,   tc_b_mv,   tc_k_mv,   tc_n_mv,   tc_e_mv,   tc_j_mv,   tc_t_mv,
       tc_w_mv,   tc_l_mv,   tc_u_mv,   Pt100_r,   Cu50_r,    Cu100_r};
float code * k_ad[14] = {
       tc_s_k,   tc_r_k,     tc_b_k,    tc_k_k,    tc_n_k,    tc_e_k,    tc_j_k,    tc_t_k,
       tc_w_k,   tc_l_k,     tc_u_k,    Pt100_k,   Cu50_k,    Cu100_k};
float code * b_ad[14] = {
       tc_s_b,   tc_r_b,     tc_b_b,    tc_k_b,    tc_n_b,    tc_e_b,    tc_j_b,    tc_t_b,
       tc_w_b,   tc_l_b,     tc_u_b,    Pt100_b,   Cu50_b,    Cu100_b};


float code cold_s_t[2] = { 29.6000000, 49.9000000};
float code cold_s_k[2] = {  0.0057582,  0.0063006};
float code cold_s_b[2] = { -0.0017172, -0.0168099};

float code cold_r_t[2] = { 27.8000000, 49.9000000};
float code cold_r_k[2] = {  0.0056605,  0.0062693};
float code cold_r_b[2] = { -0.0016878, -0.0179079};

float code cold_b_t[1] = { 49.9000000};
float code cold_b_k[1] = {  0.0000000};
float code cold_b_b[1] = {  0.0000000};

float code cold_k_t[2] = { 33.8000000,   50.0000000};
float code cold_k_k[2] = {  0.0401914,    0.0410480};
float code cold_k_b[2] = { -0.0040109,   -0.0298753};

float code cold_n_t[2] = {30.2000000,   50.0000000};
float code cold_n_k[2] = {0.0264346,    0.0273441};
float code cold_n_b[2] = {-0.0025862,   -0.0286097};

float code cold_e_t[2] = { 28.1000000,   50.0000000};
float code cold_e_k[2] = {  0.0599459,    0.0622380};
float code cold_e_b[2] = { -0.0059942,   -0.0679944};

float code cold_j_t[2] = { 33.6500000,   50.0000000};
float code cold_j_k[2] = {  0.0513233,    0.0525153};
float code cold_j_b[2] = { -0.0051234,   -0.0413526};

float code cold_t_t[3] = {24.6500000, 48.8000000, 50.0000000};
float code cold_t_k[3] = { 0.0396581,  0.0416831,  0.0427692};
float code cold_t_b[3] = {-0.0038380, -0.0538953, -0.1027471};

float code cold_w_t[2] = { 30.000000, 49.9000000};
float code cold_w_k[2] = { 0.0101757,  0.0113753};
float code cold_w_b[2] = { -0.0030351,-0.0396294};

float code cold_l_t[2] = { 45.000000, 49.9000000};
float code cold_l_k[2] = {  0.052673426, 0.054269457};
float code cold_l_b[2] = {  0.000000, -0.06543419};

float code cold_u_t[2] = { 30.000000, 49.9000000};
float code cold_u_k[2] = {  0.03979952, 0.04308142};
float code cold_u_b[2] = {  0.000000, -0.096005895};

float code * cold_t[11] = {
      cold_s_t,   cold_r_t,   cold_b_t,   cold_k_t,   cold_n_t,   cold_e_t, 
      cold_j_t,   cold_t_t,   cold_w_t,   cold_l_t,   cold_u_t};

float code * cold_k[11] = {
      cold_s_k,   cold_r_k,   cold_b_k,   cold_k_k,   cold_n_k,   cold_e_k, 
      cold_j_k,   cold_t_k,   cold_w_k,   cold_l_k,   cold_u_k};

float code * cold_b[11] = {
      cold_s_b,   cold_r_b,   cold_b_b,   cold_k_b,   cold_n_b,   cold_e_b, 
      cold_j_b,   cold_t_b,   cold_w_b,   cold_l_b,   cold_u_b};
