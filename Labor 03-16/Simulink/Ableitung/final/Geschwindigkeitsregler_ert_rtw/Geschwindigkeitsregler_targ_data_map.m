  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 18;
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
    ;% Auto data (Geschwindigkeitsregler_P)
    ;%
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_P.AB1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Geschwindigkeitsregler_P.AB2
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 4;
	
	  ;% Geschwindigkeitsregler_P.AD
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 7;
	
	  ;% Geschwindigkeitsregler_P.BD
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 16;
	
	  ;% Geschwindigkeitsregler_P.DiscretePIDController_LowerSatu
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 28;
	
	  ;% Geschwindigkeitsregler_P.DiscretePIDController_LowerSa_p
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 29;
	
	  ;% Geschwindigkeitsregler_P.DiscretePIDController_LowerS_pn
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 30;
	
	  ;% Geschwindigkeitsregler_P.DiscretePIDController_LowerSa_e
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 31;
	
	  ;% Geschwindigkeitsregler_P.DiscretePIDController_UpperSatu
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 32;
	
	  ;% Geschwindigkeitsregler_P.DiscretePIDController_UpperSa_b
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 33;
	
	  ;% Geschwindigkeitsregler_P.DiscretePIDController_UpperSa_o
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 34;
	
	  ;% Geschwindigkeitsregler_P.DiscretePIDController_UpperSa_l
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 35;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_P.DigitalOutput_pinNumber
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Geschwindigkeitsregler_P.PWM_pinNumber
	  section.data(2).logicalSrcIdx = 13;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Geschwindigkeitsregler_P.DigitalOutput_pinNumber_n
	  section.data(3).logicalSrcIdx = 14;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Geschwindigkeitsregler_P.PWM_pinNumber_g
	  section.data(4).logicalSrcIdx = 15;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_P.DetectRisePositive_vinit
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Geschwindigkeitsregler_P.DetectRisePositive1_vinit
	  section.data(2).logicalSrcIdx = 17;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Geschwindigkeitsregler_P.DetectRisePositive2_vinit
	  section.data(3).logicalSrcIdx = 18;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Geschwindigkeitsregler_P.DetectRisePositive3_vinit
	  section.data(4).logicalSrcIdx = 19;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 51;
      section.data(51)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_P.Constant2_Value
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Geschwindigkeitsregler_P.Switch_Threshold
	  section.data(2).logicalSrcIdx = 21;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Geschwindigkeitsregler_P.Constant3_Value
	  section.data(3).logicalSrcIdx = 22;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Geschwindigkeitsregler_P.Switch1_Threshold
	  section.data(4).logicalSrcIdx = 23;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Geschwindigkeitsregler_P.Constant2_Value_j
	  section.data(5).logicalSrcIdx = 24;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Geschwindigkeitsregler_P.Switch_Threshold_n
	  section.data(6).logicalSrcIdx = 25;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Geschwindigkeitsregler_P.Constant3_Value_k
	  section.data(7).logicalSrcIdx = 26;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Geschwindigkeitsregler_P.Switch1_Threshold_k
	  section.data(8).logicalSrcIdx = 27;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Geschwindigkeitsregler_P.enable_Value
	  section.data(9).logicalSrcIdx = 28;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Geschwindigkeitsregler_P.Constant1_Value
	  section.data(10).logicalSrcIdx = 29;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Geschwindigkeitsregler_P.Constant_Value
	  section.data(11).logicalSrcIdx = 30;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Geschwindigkeitsregler_P.Zustandsvariablenfilter_C
	  section.data(12).logicalSrcIdx = 31;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Geschwindigkeitsregler_P.Zustandsvariablenfilter_D
	  section.data(13).logicalSrcIdx = 32;
	  section.data(13).dtTransOffset = 20;
	
	  ;% Geschwindigkeitsregler_P.Constant2_Value_n
	  section.data(14).logicalSrcIdx = 33;
	  section.data(14).dtTransOffset = 32;
	
	  ;% Geschwindigkeitsregler_P.Constant3_Value_i
	  section.data(15).logicalSrcIdx = 34;
	  section.data(15).dtTransOffset = 33;
	
	  ;% Geschwindigkeitsregler_P.Integrator_gainval
	  section.data(16).logicalSrcIdx = 35;
	  section.data(16).dtTransOffset = 34;
	
	  ;% Geschwindigkeitsregler_P.Integrator_IC
	  section.data(17).logicalSrcIdx = 36;
	  section.data(17).dtTransOffset = 35;
	
	  ;% Geschwindigkeitsregler_P.direction_Value
	  section.data(18).logicalSrcIdx = 37;
	  section.data(18).dtTransOffset = 36;
	
	  ;% Geschwindigkeitsregler_P.maxClicksproSec_Value
	  section.data(19).logicalSrcIdx = 38;
	  section.data(19).dtTransOffset = 37;
	
	  ;% Geschwindigkeitsregler_P.prozent_Value
	  section.data(20).logicalSrcIdx = 39;
	  section.data(20).dtTransOffset = 38;
	
	  ;% Geschwindigkeitsregler_P.Zustandsvariablenfilter_C_n
	  section.data(21).logicalSrcIdx = 40;
	  section.data(21).dtTransOffset = 39;
	
	  ;% Geschwindigkeitsregler_P.Zustandsvariablenfilter_D_m
	  section.data(22).logicalSrcIdx = 41;
	  section.data(22).dtTransOffset = 48;
	
	  ;% Geschwindigkeitsregler_P.p_Value
	  section.data(23).logicalSrcIdx = 42;
	  section.data(23).dtTransOffset = 60;
	
	  ;% Geschwindigkeitsregler_P.i_Value
	  section.data(24).logicalSrcIdx = 43;
	  section.data(24).dtTransOffset = 61;
	
	  ;% Geschwindigkeitsregler_P.Integrator_gainval_o
	  section.data(25).logicalSrcIdx = 44;
	  section.data(25).dtTransOffset = 62;
	
	  ;% Geschwindigkeitsregler_P.Integrator_IC_f
	  section.data(26).logicalSrcIdx = 45;
	  section.data(26).dtTransOffset = 63;
	
	  ;% Geschwindigkeitsregler_P.Constant1_Value_c
	  section.data(27).logicalSrcIdx = 46;
	  section.data(27).dtTransOffset = 64;
	
	  ;% Geschwindigkeitsregler_P.Constant_Value_f
	  section.data(28).logicalSrcIdx = 47;
	  section.data(28).dtTransOffset = 65;
	
	  ;% Geschwindigkeitsregler_P.Zustandsvariablenfilter_C_m
	  section.data(29).logicalSrcIdx = 48;
	  section.data(29).dtTransOffset = 66;
	
	  ;% Geschwindigkeitsregler_P.Zustandsvariablenfilter_D_l
	  section.data(30).logicalSrcIdx = 49;
	  section.data(30).dtTransOffset = 75;
	
	  ;% Geschwindigkeitsregler_P.Constant2_Value_l
	  section.data(31).logicalSrcIdx = 50;
	  section.data(31).dtTransOffset = 87;
	
	  ;% Geschwindigkeitsregler_P.Constant3_Value_m
	  section.data(32).logicalSrcIdx = 51;
	  section.data(32).dtTransOffset = 88;
	
	  ;% Geschwindigkeitsregler_P.Integrator_gainval_k
	  section.data(33).logicalSrcIdx = 52;
	  section.data(33).dtTransOffset = 89;
	
	  ;% Geschwindigkeitsregler_P.Integrator_IC_n
	  section.data(34).logicalSrcIdx = 53;
	  section.data(34).dtTransOffset = 90;
	
	  ;% Geschwindigkeitsregler_P.Constant1_Value_e
	  section.data(35).logicalSrcIdx = 54;
	  section.data(35).dtTransOffset = 91;
	
	  ;% Geschwindigkeitsregler_P.Constant_Value_o
	  section.data(36).logicalSrcIdx = 55;
	  section.data(36).dtTransOffset = 92;
	
	  ;% Geschwindigkeitsregler_P.Zustandsvariablenfilter_C_p
	  section.data(37).logicalSrcIdx = 56;
	  section.data(37).dtTransOffset = 93;
	
	  ;% Geschwindigkeitsregler_P.Zustandsvariablenfilter_D_p
	  section.data(38).logicalSrcIdx = 57;
	  section.data(38).dtTransOffset = 102;
	
	  ;% Geschwindigkeitsregler_P.Constant2_Value_i
	  section.data(39).logicalSrcIdx = 58;
	  section.data(39).dtTransOffset = 114;
	
	  ;% Geschwindigkeitsregler_P.Constant3_Value_e
	  section.data(40).logicalSrcIdx = 59;
	  section.data(40).dtTransOffset = 115;
	
	  ;% Geschwindigkeitsregler_P.Integrator_gainval_n
	  section.data(41).logicalSrcIdx = 60;
	  section.data(41).dtTransOffset = 116;
	
	  ;% Geschwindigkeitsregler_P.Integrator_IC_i
	  section.data(42).logicalSrcIdx = 61;
	  section.data(42).dtTransOffset = 117;
	
	  ;% Geschwindigkeitsregler_P.Constant_Value_j
	  section.data(43).logicalSrcIdx = 62;
	  section.data(43).dtTransOffset = 118;
	
	  ;% Geschwindigkeitsregler_P.r1Altwerte_A
	  section.data(44).logicalSrcIdx = 63;
	  section.data(44).dtTransOffset = 119;
	
	  ;% Geschwindigkeitsregler_P.r1Altwerte_C
	  section.data(45).logicalSrcIdx = 64;
	  section.data(45).dtTransOffset = 123;
	
	  ;% Geschwindigkeitsregler_P.r1Altwerte_A_i
	  section.data(46).logicalSrcIdx = 66;
	  section.data(46).dtTransOffset = 139;
	
	  ;% Geschwindigkeitsregler_P.r1Altwerte_C_b
	  section.data(47).logicalSrcIdx = 67;
	  section.data(47).dtTransOffset = 143;
	
	  ;% Geschwindigkeitsregler_P.r1Altwerte_A_h
	  section.data(48).logicalSrcIdx = 69;
	  section.data(48).dtTransOffset = 159;
	
	  ;% Geschwindigkeitsregler_P.r1Altwerte_C_j
	  section.data(49).logicalSrcIdx = 70;
	  section.data(49).dtTransOffset = 163;
	
	  ;% Geschwindigkeitsregler_P.r1Altwerte_A_ix
	  section.data(50).logicalSrcIdx = 72;
	  section.data(50).dtTransOffset = 179;
	
	  ;% Geschwindigkeitsregler_P.r1Altwerte_C_js
	  section.data(51).logicalSrcIdx = 73;
	  section.data(51).dtTransOffset = 183;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_P.HL_p1
	  section.data(1).logicalSrcIdx = 75;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Geschwindigkeitsregler_P.HR_p1
	  section.data(2).logicalSrcIdx = 76;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Geschwindigkeitsregler_P.VR_p1
	  section.data(3).logicalSrcIdx = 77;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Geschwindigkeitsregler_P.VL_p1
	  section.data(4).logicalSrcIdx = 78;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_P.Constant_Value_k
	  section.data(1).logicalSrcIdx = 79;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Geschwindigkeitsregler_P.Constant_Value_fr
	  section.data(2).logicalSrcIdx = 80;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Geschwindigkeitsregler_P.Constant_Value_od
	  section.data(3).logicalSrcIdx = 81;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Geschwindigkeitsregler_P.Constant_Value_fp
	  section.data(4).logicalSrcIdx = 82;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_P.Subsystem3.Constant1_Value
	  section.data(1).logicalSrcIdx = 83;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Geschwindigkeitsregler_P.Subsystem3.Out1_Y0
	  section.data(2).logicalSrcIdx = 84;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Geschwindigkeitsregler_P.Subsystem3.Delay_InitialCondition
	  section.data(3).logicalSrcIdx = 85;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Geschwindigkeitsregler_P.Subsystem3.Switch_Threshold
	  section.data(4).logicalSrcIdx = 86;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Geschwindigkeitsregler_P.Subsystem3.Constant_Value
	  section.data(5).logicalSrcIdx = 87;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_P.Subsystem3.Delay_DelayLength
	  section.data(1).logicalSrcIdx = 88;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_P.Subsystem2.Constant1_Value
	  section.data(1).logicalSrcIdx = 89;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Geschwindigkeitsregler_P.Subsystem2.Out1_Y0
	  section.data(2).logicalSrcIdx = 90;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Geschwindigkeitsregler_P.Subsystem2.Delay_InitialCondition
	  section.data(3).logicalSrcIdx = 91;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Geschwindigkeitsregler_P.Subsystem2.Switch_Threshold
	  section.data(4).logicalSrcIdx = 92;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Geschwindigkeitsregler_P.Subsystem2.Constant_Value
	  section.data(5).logicalSrcIdx = 93;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_P.Subsystem2.Delay_DelayLength
	  section.data(1).logicalSrcIdx = 94;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(10) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_P.Subsystem1.Constant1_Value
	  section.data(1).logicalSrcIdx = 95;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Geschwindigkeitsregler_P.Subsystem1.Out1_Y0
	  section.data(2).logicalSrcIdx = 96;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Geschwindigkeitsregler_P.Subsystem1.Delay_InitialCondition
	  section.data(3).logicalSrcIdx = 97;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Geschwindigkeitsregler_P.Subsystem1.Switch_Threshold
	  section.data(4).logicalSrcIdx = 98;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Geschwindigkeitsregler_P.Subsystem1.Constant_Value
	  section.data(5).logicalSrcIdx = 99;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_P.Subsystem1.Delay_DelayLength
	  section.data(1).logicalSrcIdx = 100;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(12) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_P.Subsystem.Constant1_Value
	  section.data(1).logicalSrcIdx = 101;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Geschwindigkeitsregler_P.Subsystem.Out1_Y0
	  section.data(2).logicalSrcIdx = 102;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Geschwindigkeitsregler_P.Subsystem.Delay_InitialCondition
	  section.data(3).logicalSrcIdx = 103;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Geschwindigkeitsregler_P.Subsystem.Switch_Threshold
	  section.data(4).logicalSrcIdx = 104;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Geschwindigkeitsregler_P.Subsystem.Constant_Value
	  section.data(5).logicalSrcIdx = 105;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_P.Subsystem.Delay_DelayLength
	  section.data(1).logicalSrcIdx = 106;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(14) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_P.vl.DigitalOutput_pinNumber
	  section.data(1).logicalSrcIdx = 107;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Geschwindigkeitsregler_P.vl.PWM_pinNumber
	  section.data(2).logicalSrcIdx = 108;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(15) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_P.vl.Constant2_Value
	  section.data(1).logicalSrcIdx = 109;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Geschwindigkeitsregler_P.vl.Switch_Threshold
	  section.data(2).logicalSrcIdx = 110;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Geschwindigkeitsregler_P.vl.Constant3_Value
	  section.data(3).logicalSrcIdx = 111;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Geschwindigkeitsregler_P.vl.Switch1_Threshold
	  section.data(4).logicalSrcIdx = 112;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(16) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_P.hl.DigitalOutput_pinNumber
	  section.data(1).logicalSrcIdx = 113;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Geschwindigkeitsregler_P.hl.PWM_pinNumber
	  section.data(2).logicalSrcIdx = 114;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(17) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_P.hl.Constant2_Value
	  section.data(1).logicalSrcIdx = 115;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Geschwindigkeitsregler_P.hl.Switch_Threshold
	  section.data(2).logicalSrcIdx = 116;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Geschwindigkeitsregler_P.hl.Constant3_Value
	  section.data(3).logicalSrcIdx = 117;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Geschwindigkeitsregler_P.hl.Switch1_Threshold
	  section.data(4).logicalSrcIdx = 118;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(18) = section;
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
    nTotSects     = 8;
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
    ;% Auto data (Geschwindigkeitsregler_B)
    ;%
      section.nData     = 19;
      section.data(19)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_B.FromWs
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Geschwindigkeitsregler_B.Zustandsvariablenfilter
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% Geschwindigkeitsregler_B.IOut
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 5;
	
	  ;% Geschwindigkeitsregler_B.Integrator
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 6;
	
	  ;% Geschwindigkeitsregler_B.Zustandsvariablenfilter_g
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 7;
	
	  ;% Geschwindigkeitsregler_B.Add
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 10;
	
	  ;% Geschwindigkeitsregler_B.IOut_p
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 11;
	
	  ;% Geschwindigkeitsregler_B.Integrator_n
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 12;
	
	  ;% Geschwindigkeitsregler_B.Saturate
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 13;
	
	  ;% Geschwindigkeitsregler_B.Zustandsvariablenfilter_a
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 14;
	
	  ;% Geschwindigkeitsregler_B.IOut_d
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 17;
	
	  ;% Geschwindigkeitsregler_B.Integrator_i
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 18;
	
	  ;% Geschwindigkeitsregler_B.Zustandsvariablenfilter_d
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 19;
	
	  ;% Geschwindigkeitsregler_B.IOut_dm
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 22;
	
	  ;% Geschwindigkeitsregler_B.Integrator_i4
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 23;
	
	  ;% Geschwindigkeitsregler_B.r1Altwerte
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 24;
	
	  ;% Geschwindigkeitsregler_B.r1Altwerte_n
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 28;
	
	  ;% Geschwindigkeitsregler_B.r1Altwerte_o
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 32;
	
	  ;% Geschwindigkeitsregler_B.r1Altwerte_h
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 36;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_B.DataTypeConversion
	  section.data(1).logicalSrcIdx = 19;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Geschwindigkeitsregler_B.DataTypeConversion_i
	  section.data(2).logicalSrcIdx = 20;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_B.Subsystem3.Add
	  section.data(1).logicalSrcIdx = 21;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_B.Subsystem2.Add
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_B.Subsystem1.Add
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_B.Subsystem.Add
	  section.data(1).logicalSrcIdx = 24;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_B.vl.DataTypeConversion
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_B.hl.DataTypeConversion
	  section.data(1).logicalSrcIdx = 26;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(8) = section;
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
    nTotSects     = 12;
    sectIdxOffset = 8;
    
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
    ;% Auto data (Geschwindigkeitsregler_DW)
    ;%
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Geschwindigkeitsregler_DW.Integrator_DSTATE
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3;
	
	  ;% Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_n
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 4;
	
	  ;% Geschwindigkeitsregler_DW.Integrator_DSTATE_g
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 7;
	
	  ;% Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_o
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 8;
	
	  ;% Geschwindigkeitsregler_DW.Integrator_DSTATE_k
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 11;
	
	  ;% Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_c
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 12;
	
	  ;% Geschwindigkeitsregler_DW.Integrator_DSTATE_gl
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 15;
	
	  ;% Geschwindigkeitsregler_DW.r1Altwerte_DSTATE
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 16;
	
	  ;% Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_o
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 20;
	
	  ;% Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_a
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 24;
	
	  ;% Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_g
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 28;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_DW.FromWs_PWORK.TimePtr
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Geschwindigkeitsregler_DW.Scope_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 13;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_DW.FromWs_IWORK.PrevIndex
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_DW.DelayInput1_DSTATE
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Geschwindigkeitsregler_DW.DelayInput1_DSTATE_c
	  section.data(2).logicalSrcIdx = 16;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Geschwindigkeitsregler_DW.DelayInput1_DSTATE_o
	  section.data(3).logicalSrcIdx = 17;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Geschwindigkeitsregler_DW.DelayInput1_DSTATE_ol
	  section.data(4).logicalSrcIdx = 18;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_DW.Subsystem3.Delay_DSTATE
	  section.data(1).logicalSrcIdx = 19;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_DW.Subsystem3.Subsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_DW.Subsystem2.Delay_DSTATE
	  section.data(1).logicalSrcIdx = 21;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_DW.Subsystem2.Subsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_DW.Subsystem1.Delay_DSTATE
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_DW.Subsystem1.Subsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 24;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_DW.Subsystem.Delay_DSTATE
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_DW.Subsystem.Subsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 26;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
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


  targMap.checksum0 = 1877328200;
  targMap.checksum1 = 874492353;
  targMap.checksum2 = 2356479961;
  targMap.checksum3 = 4197152515;

