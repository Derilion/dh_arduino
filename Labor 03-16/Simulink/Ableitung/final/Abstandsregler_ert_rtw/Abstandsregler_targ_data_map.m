  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 19;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Abstandsregler_P)
    ;%
      section.nData     = 14;
      section.data(14)  = dumData; %prealloc
      
	  ;% Abstandsregler_P.AB1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Abstandsregler_P.AB2
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 4;
	
	  ;% Abstandsregler_P.AD
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 7;
	
	  ;% Abstandsregler_P.BD
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 16;
	
	  ;% Abstandsregler_P.DiscretePIDController_LowerSatu
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 28;
	
	  ;% Abstandsregler_P.DiscretePIDController_LowerSa_i
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 29;
	
	  ;% Abstandsregler_P.DiscretePIDController_LowerSa_p
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 30;
	
	  ;% Abstandsregler_P.DiscretePIDController_LowerS_pn
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 31;
	
	  ;% Abstandsregler_P.DiscretePIDController_LowerSa_e
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 32;
	
	  ;% Abstandsregler_P.DiscretePIDController_UpperSatu
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 33;
	
	  ;% Abstandsregler_P.DiscretePIDController_UpperSa_m
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 34;
	
	  ;% Abstandsregler_P.DiscretePIDController_UpperSa_b
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 35;
	
	  ;% Abstandsregler_P.DiscretePIDController_UpperSa_o
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 36;
	
	  ;% Abstandsregler_P.DiscretePIDController_UpperSa_l
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 37;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Abstandsregler_P.DigitalOutput_pinNumber
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Abstandsregler_P.PWM_pinNumber
	  section.data(2).logicalSrcIdx = 15;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Abstandsregler_P.DigitalOutput_pinNumber_n
	  section.data(3).logicalSrcIdx = 16;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Abstandsregler_P.PWM_pinNumber_g
	  section.data(4).logicalSrcIdx = 17;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Abstandsregler_P.DetectRisePositive_vinit
	  section.data(1).logicalSrcIdx = 18;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Abstandsregler_P.DetectRisePositive1_vinit
	  section.data(2).logicalSrcIdx = 19;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Abstandsregler_P.DetectRisePositive2_vinit
	  section.data(3).logicalSrcIdx = 20;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Abstandsregler_P.DetectRisePositive3_vinit
	  section.data(4).logicalSrcIdx = 21;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 56;
      section.data(56)  = dumData; %prealloc
      
	  ;% Abstandsregler_P.Constant3_Value
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Abstandsregler_P.Constant2_Value
	  section.data(2).logicalSrcIdx = 23;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Abstandsregler_P.Switch_Threshold
	  section.data(3).logicalSrcIdx = 24;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Abstandsregler_P.Switch1_Threshold
	  section.data(4).logicalSrcIdx = 25;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Abstandsregler_P.Constant3_Value_k
	  section.data(5).logicalSrcIdx = 26;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Abstandsregler_P.Constant2_Value_j
	  section.data(6).logicalSrcIdx = 27;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Abstandsregler_P.Switch_Threshold_n
	  section.data(7).logicalSrcIdx = 28;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Abstandsregler_P.Switch1_Threshold_k
	  section.data(8).logicalSrcIdx = 29;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Abstandsregler_P.enable_Value
	  section.data(9).logicalSrcIdx = 30;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Abstandsregler_P.Constant_Value
	  section.data(10).logicalSrcIdx = 31;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Abstandsregler_P.Constant1_Value
	  section.data(11).logicalSrcIdx = 32;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Abstandsregler_P.Constant2_Value_jd
	  section.data(12).logicalSrcIdx = 33;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Abstandsregler_P.Integrator_gainval
	  section.data(13).logicalSrcIdx = 34;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Abstandsregler_P.Integrator_IC
	  section.data(14).logicalSrcIdx = 35;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Abstandsregler_P.Constant1_Value_b
	  section.data(15).logicalSrcIdx = 36;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Abstandsregler_P.Constant_Value_g
	  section.data(16).logicalSrcIdx = 37;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Abstandsregler_P.Zustandsvariablenfilter_C
	  section.data(17).logicalSrcIdx = 38;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Abstandsregler_P.Zustandsvariablenfilter_D
	  section.data(18).logicalSrcIdx = 39;
	  section.data(18).dtTransOffset = 25;
	
	  ;% Abstandsregler_P.Constant2_Value_n
	  section.data(19).logicalSrcIdx = 40;
	  section.data(19).dtTransOffset = 37;
	
	  ;% Abstandsregler_P.Constant3_Value_i
	  section.data(20).logicalSrcIdx = 41;
	  section.data(20).dtTransOffset = 38;
	
	  ;% Abstandsregler_P.Integrator_gainval_p
	  section.data(21).logicalSrcIdx = 42;
	  section.data(21).dtTransOffset = 39;
	
	  ;% Abstandsregler_P.Integrator_IC_p
	  section.data(22).logicalSrcIdx = 43;
	  section.data(22).dtTransOffset = 40;
	
	  ;% Abstandsregler_P.direction_Value
	  section.data(23).logicalSrcIdx = 44;
	  section.data(23).dtTransOffset = 41;
	
	  ;% Abstandsregler_P.maxClicksproSec_Value
	  section.data(24).logicalSrcIdx = 45;
	  section.data(24).dtTransOffset = 42;
	
	  ;% Abstandsregler_P.prozent_Value
	  section.data(25).logicalSrcIdx = 46;
	  section.data(25).dtTransOffset = 43;
	
	  ;% Abstandsregler_P.Zustandsvariablenfilter_C_n
	  section.data(26).logicalSrcIdx = 47;
	  section.data(26).dtTransOffset = 44;
	
	  ;% Abstandsregler_P.Zustandsvariablenfilter_D_m
	  section.data(27).logicalSrcIdx = 48;
	  section.data(27).dtTransOffset = 53;
	
	  ;% Abstandsregler_P.p_Value
	  section.data(28).logicalSrcIdx = 49;
	  section.data(28).dtTransOffset = 65;
	
	  ;% Abstandsregler_P.i_Value
	  section.data(29).logicalSrcIdx = 50;
	  section.data(29).dtTransOffset = 66;
	
	  ;% Abstandsregler_P.Integrator_gainval_o
	  section.data(30).logicalSrcIdx = 51;
	  section.data(30).dtTransOffset = 67;
	
	  ;% Abstandsregler_P.Integrator_IC_f
	  section.data(31).logicalSrcIdx = 52;
	  section.data(31).dtTransOffset = 68;
	
	  ;% Abstandsregler_P.Constant1_Value_c
	  section.data(32).logicalSrcIdx = 53;
	  section.data(32).dtTransOffset = 69;
	
	  ;% Abstandsregler_P.Constant_Value_f
	  section.data(33).logicalSrcIdx = 54;
	  section.data(33).dtTransOffset = 70;
	
	  ;% Abstandsregler_P.Zustandsvariablenfilter_C_m
	  section.data(34).logicalSrcIdx = 55;
	  section.data(34).dtTransOffset = 71;
	
	  ;% Abstandsregler_P.Zustandsvariablenfilter_D_l
	  section.data(35).logicalSrcIdx = 56;
	  section.data(35).dtTransOffset = 80;
	
	  ;% Abstandsregler_P.Constant2_Value_l
	  section.data(36).logicalSrcIdx = 57;
	  section.data(36).dtTransOffset = 92;
	
	  ;% Abstandsregler_P.Constant3_Value_m
	  section.data(37).logicalSrcIdx = 58;
	  section.data(37).dtTransOffset = 93;
	
	  ;% Abstandsregler_P.Integrator_gainval_k
	  section.data(38).logicalSrcIdx = 59;
	  section.data(38).dtTransOffset = 94;
	
	  ;% Abstandsregler_P.Integrator_IC_n
	  section.data(39).logicalSrcIdx = 60;
	  section.data(39).dtTransOffset = 95;
	
	  ;% Abstandsregler_P.Constant1_Value_e
	  section.data(40).logicalSrcIdx = 61;
	  section.data(40).dtTransOffset = 96;
	
	  ;% Abstandsregler_P.Constant_Value_o
	  section.data(41).logicalSrcIdx = 62;
	  section.data(41).dtTransOffset = 97;
	
	  ;% Abstandsregler_P.Zustandsvariablenfilter_C_p
	  section.data(42).logicalSrcIdx = 63;
	  section.data(42).dtTransOffset = 98;
	
	  ;% Abstandsregler_P.Zustandsvariablenfilter_D_p
	  section.data(43).logicalSrcIdx = 64;
	  section.data(43).dtTransOffset = 107;
	
	  ;% Abstandsregler_P.Constant2_Value_i
	  section.data(44).logicalSrcIdx = 65;
	  section.data(44).dtTransOffset = 119;
	
	  ;% Abstandsregler_P.Constant3_Value_e
	  section.data(45).logicalSrcIdx = 66;
	  section.data(45).dtTransOffset = 120;
	
	  ;% Abstandsregler_P.Integrator_gainval_n
	  section.data(46).logicalSrcIdx = 67;
	  section.data(46).dtTransOffset = 121;
	
	  ;% Abstandsregler_P.Integrator_IC_i
	  section.data(47).logicalSrcIdx = 68;
	  section.data(47).dtTransOffset = 122;
	
	  ;% Abstandsregler_P.Constant_Value_j
	  section.data(48).logicalSrcIdx = 69;
	  section.data(48).dtTransOffset = 123;
	
	  ;% Abstandsregler_P.r1Altwerte_A
	  section.data(49).logicalSrcIdx = 70;
	  section.data(49).dtTransOffset = 124;
	
	  ;% Abstandsregler_P.r1Altwerte_C
	  section.data(50).logicalSrcIdx = 71;
	  section.data(50).dtTransOffset = 128;
	
	  ;% Abstandsregler_P.r1Altwerte_A_i
	  section.data(51).logicalSrcIdx = 73;
	  section.data(51).dtTransOffset = 144;
	
	  ;% Abstandsregler_P.r1Altwerte_C_b
	  section.data(52).logicalSrcIdx = 74;
	  section.data(52).dtTransOffset = 148;
	
	  ;% Abstandsregler_P.r1Altwerte_A_h
	  section.data(53).logicalSrcIdx = 76;
	  section.data(53).dtTransOffset = 164;
	
	  ;% Abstandsregler_P.r1Altwerte_C_j
	  section.data(54).logicalSrcIdx = 77;
	  section.data(54).dtTransOffset = 168;
	
	  ;% Abstandsregler_P.r1Altwerte_A_ix
	  section.data(55).logicalSrcIdx = 79;
	  section.data(55).dtTransOffset = 184;
	
	  ;% Abstandsregler_P.r1Altwerte_C_js
	  section.data(56).logicalSrcIdx = 80;
	  section.data(56).dtTransOffset = 188;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Abstandsregler_P.Abstandssensor_p1
	  section.data(1).logicalSrcIdx = 82;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Abstandsregler_P.HL_p1
	  section.data(2).logicalSrcIdx = 83;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Abstandsregler_P.HR_p1
	  section.data(3).logicalSrcIdx = 84;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Abstandsregler_P.VR_p1
	  section.data(4).logicalSrcIdx = 85;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Abstandsregler_P.VL_p1
	  section.data(5).logicalSrcIdx = 86;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Abstandsregler_P.Gain_Gain
	  section.data(1).logicalSrcIdx = 87;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Abstandsregler_P.Constant_Value_k
	  section.data(1).logicalSrcIdx = 88;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Abstandsregler_P.Constant_Value_fr
	  section.data(2).logicalSrcIdx = 89;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Abstandsregler_P.Constant_Value_od
	  section.data(3).logicalSrcIdx = 90;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Abstandsregler_P.Constant_Value_fp
	  section.data(4).logicalSrcIdx = 91;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Abstandsregler_P.Subsystem3.Constant1_Value
	  section.data(1).logicalSrcIdx = 92;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Abstandsregler_P.Subsystem3.Out1_Y0
	  section.data(2).logicalSrcIdx = 93;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Abstandsregler_P.Subsystem3.Delay_InitialCondition
	  section.data(3).logicalSrcIdx = 94;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Abstandsregler_P.Subsystem3.Switch_Threshold
	  section.data(4).logicalSrcIdx = 95;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Abstandsregler_P.Subsystem3.Constant_Value
	  section.data(5).logicalSrcIdx = 96;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Abstandsregler_P.Subsystem3.Delay_DelayLength
	  section.data(1).logicalSrcIdx = 97;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(9) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Abstandsregler_P.Subsystem2.Constant1_Value
	  section.data(1).logicalSrcIdx = 98;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Abstandsregler_P.Subsystem2.Out1_Y0
	  section.data(2).logicalSrcIdx = 99;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Abstandsregler_P.Subsystem2.Delay_InitialCondition
	  section.data(3).logicalSrcIdx = 100;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Abstandsregler_P.Subsystem2.Switch_Threshold
	  section.data(4).logicalSrcIdx = 101;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Abstandsregler_P.Subsystem2.Constant_Value
	  section.data(5).logicalSrcIdx = 102;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Abstandsregler_P.Subsystem2.Delay_DelayLength
	  section.data(1).logicalSrcIdx = 103;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(11) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Abstandsregler_P.Subsystem1.Constant1_Value
	  section.data(1).logicalSrcIdx = 104;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Abstandsregler_P.Subsystem1.Out1_Y0
	  section.data(2).logicalSrcIdx = 105;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Abstandsregler_P.Subsystem1.Delay_InitialCondition
	  section.data(3).logicalSrcIdx = 106;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Abstandsregler_P.Subsystem1.Switch_Threshold
	  section.data(4).logicalSrcIdx = 107;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Abstandsregler_P.Subsystem1.Constant_Value
	  section.data(5).logicalSrcIdx = 108;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Abstandsregler_P.Subsystem1.Delay_DelayLength
	  section.data(1).logicalSrcIdx = 109;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(13) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Abstandsregler_P.Subsystem.Constant1_Value
	  section.data(1).logicalSrcIdx = 110;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Abstandsregler_P.Subsystem.Out1_Y0
	  section.data(2).logicalSrcIdx = 111;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Abstandsregler_P.Subsystem.Delay_InitialCondition
	  section.data(3).logicalSrcIdx = 112;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Abstandsregler_P.Subsystem.Switch_Threshold
	  section.data(4).logicalSrcIdx = 113;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Abstandsregler_P.Subsystem.Constant_Value
	  section.data(5).logicalSrcIdx = 114;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Abstandsregler_P.Subsystem.Delay_DelayLength
	  section.data(1).logicalSrcIdx = 115;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(15) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Abstandsregler_P.vl.DigitalOutput_pinNumber
	  section.data(1).logicalSrcIdx = 116;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Abstandsregler_P.vl.PWM_pinNumber
	  section.data(2).logicalSrcIdx = 117;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(16) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Abstandsregler_P.vl.Constant3_Value
	  section.data(1).logicalSrcIdx = 118;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Abstandsregler_P.vl.Constant2_Value
	  section.data(2).logicalSrcIdx = 119;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Abstandsregler_P.vl.Switch_Threshold
	  section.data(3).logicalSrcIdx = 120;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Abstandsregler_P.vl.Switch1_Threshold
	  section.data(4).logicalSrcIdx = 121;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(17) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Abstandsregler_P.hl.DigitalOutput_pinNumber
	  section.data(1).logicalSrcIdx = 122;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Abstandsregler_P.hl.PWM_pinNumber
	  section.data(2).logicalSrcIdx = 123;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(18) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Abstandsregler_P.hl.Constant3_Value
	  section.data(1).logicalSrcIdx = 124;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Abstandsregler_P.hl.Constant2_Value
	  section.data(2).logicalSrcIdx = 125;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Abstandsregler_P.hl.Switch_Threshold
	  section.data(3).logicalSrcIdx = 126;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Abstandsregler_P.hl.Switch1_Threshold
	  section.data(4).logicalSrcIdx = 127;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(19) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 6;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Abstandsregler_B)
    ;%
      section.nData     = 14;
      section.data(14)  = dumData; %prealloc
      
	  ;% Abstandsregler_B.Add
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Abstandsregler_B.Integrator
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Abstandsregler_B.Saturate
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Abstandsregler_B.Integrator_i
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Abstandsregler_B.Zustandsvariablenfilter
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Abstandsregler_B.Add_d
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 7;
	
	  ;% Abstandsregler_B.Integrator_n
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 8;
	
	  ;% Abstandsregler_B.Saturate_f
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 9;
	
	  ;% Abstandsregler_B.Integrator_is
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 10;
	
	  ;% Abstandsregler_B.Integrator_i4
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 11;
	
	  ;% Abstandsregler_B.r1Altwerte
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 12;
	
	  ;% Abstandsregler_B.r1Altwerte_n
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 16;
	
	  ;% Abstandsregler_B.r1Altwerte_o
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 20;
	
	  ;% Abstandsregler_B.r1Altwerte_h
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 24;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Abstandsregler_B.Gain
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Abstandsregler_B.Subsystem3.Add
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Abstandsregler_B.Subsystem2.Add
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Abstandsregler_B.Subsystem1.Add
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Abstandsregler_B.Subsystem.Add
	  section.data(1).logicalSrcIdx = 18;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 11;
    sectIdxOffset = 6;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Abstandsregler_DW)
    ;%
      section.nData     = 13;
      section.data(13)  = dumData; %prealloc
      
	  ;% Abstandsregler_DW.Integrator_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Abstandsregler_DW.Zustandsvariablenfilter_DSTATE
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Abstandsregler_DW.Integrator_DSTATE_o
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 4;
	
	  ;% Abstandsregler_DW.Zustandsvariablenfilter_DSTAT_n
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 5;
	
	  ;% Abstandsregler_DW.Integrator_DSTATE_g
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 8;
	
	  ;% Abstandsregler_DW.Zustandsvariablenfilter_DSTAT_o
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 9;
	
	  ;% Abstandsregler_DW.Integrator_DSTATE_k
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 12;
	
	  ;% Abstandsregler_DW.Zustandsvariablenfilter_DSTAT_c
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 13;
	
	  ;% Abstandsregler_DW.Integrator_DSTATE_gl
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 16;
	
	  ;% Abstandsregler_DW.r1Altwerte_DSTATE
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 17;
	
	  ;% Abstandsregler_DW.r1Altwerte_DSTATE_o
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 21;
	
	  ;% Abstandsregler_DW.r1Altwerte_DSTATE_a
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 25;
	
	  ;% Abstandsregler_DW.r1Altwerte_DSTATE_g
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 29;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Abstandsregler_DW.Scope_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Abstandsregler_DW.Scope_PWORK_c.LoggedData
	  section.data(2).logicalSrcIdx = 14;
	  section.data(2).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Abstandsregler_DW.DelayInput1_DSTATE
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Abstandsregler_DW.DelayInput1_DSTATE_c
	  section.data(2).logicalSrcIdx = 16;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Abstandsregler_DW.DelayInput1_DSTATE_o
	  section.data(3).logicalSrcIdx = 17;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Abstandsregler_DW.DelayInput1_DSTATE_ol
	  section.data(4).logicalSrcIdx = 18;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Abstandsregler_DW.Subsystem3.Delay_DSTATE
	  section.data(1).logicalSrcIdx = 19;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Abstandsregler_DW.Subsystem3.Subsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Abstandsregler_DW.Subsystem2.Delay_DSTATE
	  section.data(1).logicalSrcIdx = 21;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Abstandsregler_DW.Subsystem2.Subsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Abstandsregler_DW.Subsystem1.Delay_DSTATE
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Abstandsregler_DW.Subsystem1.Subsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 24;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Abstandsregler_DW.Subsystem.Delay_DSTATE
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Abstandsregler_DW.Subsystem.Subsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 26;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 2178771138;
  targMap.checksum1 = 180325398;
  targMap.checksum2 = 1871106949;
  targMap.checksum3 = 2760714203;

