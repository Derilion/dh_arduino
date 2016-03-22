  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 15;
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
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
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
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_P.DigitalOutput_pinNumber
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Geschwindigkeitsregler_P.PWM_pinNumber
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Geschwindigkeitsregler_P.DigitalOutput_pinNumber_n
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Geschwindigkeitsregler_P.PWM_pinNumber_g
	  section.data(4).logicalSrcIdx = 7;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_P.DetectRisePositive_vinit
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Geschwindigkeitsregler_P.DetectRisePositive1_vinit
	  section.data(2).logicalSrcIdx = 9;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Geschwindigkeitsregler_P.DetectRisePositive2_vinit
	  section.data(3).logicalSrcIdx = 10;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Geschwindigkeitsregler_P.DetectRisePositive3_vinit
	  section.data(4).logicalSrcIdx = 11;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 38;
      section.data(38)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_P.Constant2_Value
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Geschwindigkeitsregler_P.Switch_Threshold
	  section.data(2).logicalSrcIdx = 13;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Geschwindigkeitsregler_P.Constant3_Value
	  section.data(3).logicalSrcIdx = 14;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Geschwindigkeitsregler_P.Switch1_Threshold
	  section.data(4).logicalSrcIdx = 15;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Geschwindigkeitsregler_P.Constant2_Value_j
	  section.data(5).logicalSrcIdx = 16;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Geschwindigkeitsregler_P.Switch_Threshold_n
	  section.data(6).logicalSrcIdx = 17;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Geschwindigkeitsregler_P.Constant3_Value_k
	  section.data(7).logicalSrcIdx = 18;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Geschwindigkeitsregler_P.Switch1_Threshold_k
	  section.data(8).logicalSrcIdx = 19;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Geschwindigkeitsregler_P.Out1_Y0
	  section.data(9).logicalSrcIdx = 20;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Geschwindigkeitsregler_P.Out1_Y0_a
	  section.data(10).logicalSrcIdx = 21;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Geschwindigkeitsregler_P.powerMAX4_Value
	  section.data(11).logicalSrcIdx = 22;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Geschwindigkeitsregler_P.powerMAX3_Value
	  section.data(12).logicalSrcIdx = 23;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Geschwindigkeitsregler_P.powerMAX2_Value
	  section.data(13).logicalSrcIdx = 24;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Geschwindigkeitsregler_P.powerMAX1_Value
	  section.data(14).logicalSrcIdx = 25;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Geschwindigkeitsregler_P.enable_Value
	  section.data(15).logicalSrcIdx = 26;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Geschwindigkeitsregler_P.direction_Value
	  section.data(16).logicalSrcIdx = 27;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Geschwindigkeitsregler_P.Constant1_Value
	  section.data(17).logicalSrcIdx = 28;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Geschwindigkeitsregler_P.Constant_Value
	  section.data(18).logicalSrcIdx = 29;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Geschwindigkeitsregler_P.Gain2_Gain
	  section.data(19).logicalSrcIdx = 30;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Geschwindigkeitsregler_P.Zustandsvariablenfilter_C
	  section.data(20).logicalSrcIdx = 31;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Geschwindigkeitsregler_P.Zustandsvariablenfilter_D
	  section.data(21).logicalSrcIdx = 32;
	  section.data(21).dtTransOffset = 28;
	
	  ;% Geschwindigkeitsregler_P.Gain1_Gain
	  section.data(22).logicalSrcIdx = 33;
	  section.data(22).dtTransOffset = 40;
	
	  ;% Geschwindigkeitsregler_P.Gain_Gain
	  section.data(23).logicalSrcIdx = 34;
	  section.data(23).dtTransOffset = 41;
	
	  ;% Geschwindigkeitsregler_P.Zustandsvariablenfilter_C_l
	  section.data(24).logicalSrcIdx = 35;
	  section.data(24).dtTransOffset = 42;
	
	  ;% Geschwindigkeitsregler_P.Zustandsvariablenfilter_D_a
	  section.data(25).logicalSrcIdx = 36;
	  section.data(25).dtTransOffset = 51;
	
	  ;% Geschwindigkeitsregler_P.Constant_Value_j
	  section.data(26).logicalSrcIdx = 37;
	  section.data(26).dtTransOffset = 63;
	
	  ;% Geschwindigkeitsregler_P.r1Altwerte_A
	  section.data(27).logicalSrcIdx = 38;
	  section.data(27).dtTransOffset = 64;
	
	  ;% Geschwindigkeitsregler_P.r1Altwerte_C
	  section.data(28).logicalSrcIdx = 39;
	  section.data(28).dtTransOffset = 68;
	
	  ;% Geschwindigkeitsregler_P.r1Altwerte_A_i
	  section.data(29).logicalSrcIdx = 41;
	  section.data(29).dtTransOffset = 84;
	
	  ;% Geschwindigkeitsregler_P.r1Altwerte_C_b
	  section.data(30).logicalSrcIdx = 42;
	  section.data(30).dtTransOffset = 88;
	
	  ;% Geschwindigkeitsregler_P.Constant1_Value_c
	  section.data(31).logicalSrcIdx = 44;
	  section.data(31).dtTransOffset = 104;
	
	  ;% Geschwindigkeitsregler_P.Constant_Value_f
	  section.data(32).logicalSrcIdx = 45;
	  section.data(32).dtTransOffset = 105;
	
	  ;% Geschwindigkeitsregler_P.powerMAX_Value
	  section.data(33).logicalSrcIdx = 46;
	  section.data(33).dtTransOffset = 106;
	
	  ;% Geschwindigkeitsregler_P.NMAX_Value
	  section.data(34).logicalSrcIdx = 47;
	  section.data(34).dtTransOffset = 107;
	
	  ;% Geschwindigkeitsregler_P.Switch_Threshold_b
	  section.data(35).logicalSrcIdx = 48;
	  section.data(35).dtTransOffset = 108;
	
	  ;% Geschwindigkeitsregler_P.Delay_InitialCondition
	  section.data(36).logicalSrcIdx = 49;
	  section.data(36).dtTransOffset = 109;
	
	  ;% Geschwindigkeitsregler_P.Switch2_Threshold
	  section.data(37).logicalSrcIdx = 50;
	  section.data(37).dtTransOffset = 110;
	
	  ;% Geschwindigkeitsregler_P.Switch1_Threshold_kd
	  section.data(38).logicalSrcIdx = 51;
	  section.data(38).dtTransOffset = 111;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_P.HL_p1
	  section.data(1).logicalSrcIdx = 52;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Geschwindigkeitsregler_P.HR_p1
	  section.data(2).logicalSrcIdx = 53;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Geschwindigkeitsregler_P.VR_p1
	  section.data(3).logicalSrcIdx = 54;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Geschwindigkeitsregler_P.VL_p1
	  section.data(4).logicalSrcIdx = 55;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_P.Delay_DelayLength
	  section.data(1).logicalSrcIdx = 56;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_P.Constant_Value_k
	  section.data(1).logicalSrcIdx = 57;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Geschwindigkeitsregler_P.Constant_Value_fr
	  section.data(2).logicalSrcIdx = 58;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Geschwindigkeitsregler_P.Constant_Value_o
	  section.data(3).logicalSrcIdx = 59;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Geschwindigkeitsregler_P.Constant_Value_fp
	  section.data(4).logicalSrcIdx = 60;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_P.Subsystem3.Constant1_Value
	  section.data(1).logicalSrcIdx = 61;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Geschwindigkeitsregler_P.Subsystem3.Out1_Y0
	  section.data(2).logicalSrcIdx = 62;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Geschwindigkeitsregler_P.Subsystem3.Delay_InitialCondition
	  section.data(3).logicalSrcIdx = 63;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Geschwindigkeitsregler_P.Subsystem3.Switch_Threshold
	  section.data(4).logicalSrcIdx = 64;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Geschwindigkeitsregler_P.Subsystem3.Constant_Value
	  section.data(5).logicalSrcIdx = 65;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_P.Subsystem3.Delay_DelayLength
	  section.data(1).logicalSrcIdx = 66;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(9) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_P.Subsystem.Constant1_Value
	  section.data(1).logicalSrcIdx = 67;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Geschwindigkeitsregler_P.Subsystem.Out1_Y0
	  section.data(2).logicalSrcIdx = 68;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Geschwindigkeitsregler_P.Subsystem.Delay_InitialCondition
	  section.data(3).logicalSrcIdx = 69;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Geschwindigkeitsregler_P.Subsystem.Switch_Threshold
	  section.data(4).logicalSrcIdx = 70;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Geschwindigkeitsregler_P.Subsystem.Constant_Value
	  section.data(5).logicalSrcIdx = 71;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_P.Subsystem.Delay_DelayLength
	  section.data(1).logicalSrcIdx = 72;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(11) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_P.vl.DigitalOutput_pinNumber
	  section.data(1).logicalSrcIdx = 73;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Geschwindigkeitsregler_P.vl.PWM_pinNumber
	  section.data(2).logicalSrcIdx = 74;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(12) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_P.vl.Constant2_Value
	  section.data(1).logicalSrcIdx = 75;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Geschwindigkeitsregler_P.vl.Switch_Threshold
	  section.data(2).logicalSrcIdx = 76;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Geschwindigkeitsregler_P.vl.Constant3_Value
	  section.data(3).logicalSrcIdx = 77;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Geschwindigkeitsregler_P.vl.Switch1_Threshold
	  section.data(4).logicalSrcIdx = 78;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(13) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_P.hl.DigitalOutput_pinNumber
	  section.data(1).logicalSrcIdx = 79;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Geschwindigkeitsregler_P.hl.PWM_pinNumber
	  section.data(2).logicalSrcIdx = 80;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(14) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_P.hl.Constant2_Value
	  section.data(1).logicalSrcIdx = 81;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Geschwindigkeitsregler_P.hl.Switch_Threshold
	  section.data(2).logicalSrcIdx = 82;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Geschwindigkeitsregler_P.hl.Constant3_Value
	  section.data(3).logicalSrcIdx = 83;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Geschwindigkeitsregler_P.hl.Switch1_Threshold
	  section.data(4).logicalSrcIdx = 84;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(15) = section;
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
    ;% Auto data (Geschwindigkeitsregler_B)
    ;%
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_B.Gain2
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Geschwindigkeitsregler_B.Zustandsvariablenfilter
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Geschwindigkeitsregler_B.Gain1
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 4;
	
	  ;% Geschwindigkeitsregler_B.Gain
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 5;
	
	  ;% Geschwindigkeitsregler_B.Zustandsvariablenfilter_d
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 6;
	
	  ;% Geschwindigkeitsregler_B.r1Altwerte
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 9;
	
	  ;% Geschwindigkeitsregler_B.r1Altwerte_n
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 13;
	
	  ;% Geschwindigkeitsregler_B.Divide
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 17;
	
	  ;% Geschwindigkeitsregler_B.diffferenzN
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 18;
	
	  ;% Geschwindigkeitsregler_B.Switch1
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 19;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_B.DataTypeConversion
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Geschwindigkeitsregler_B.DataTypeConversion_i
	  section.data(2).logicalSrcIdx = 11;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_B.Subsystem3.Add
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_B.Subsystem.Add
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_B.vl.DataTypeConversion
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_B.hl.DataTypeConversion
	  section.data(1).logicalSrcIdx = 15;
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
    nTotSects     = 9;
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
    ;% Auto data (Geschwindigkeitsregler_DW)
    ;%
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_e
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3;
	
	  ;% Geschwindigkeitsregler_DW.r1Altwerte_DSTATE
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 6;
	
	  ;% Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_o
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 10;
	
	  ;% Geschwindigkeitsregler_DW.Delay_DSTATE
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 14;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_DW.FromWs_PWORK.TimePtr
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Geschwindigkeitsregler_DW.Scope2_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 6;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Geschwindigkeitsregler_DW.Scope3_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 7;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Geschwindigkeitsregler_DW.Scope1_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 8;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Geschwindigkeitsregler_DW.Scope_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 9;
	  section.data(5).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_DW.FromWs_IWORK.PrevIndex
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_DW.DelayInput1_DSTATE
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Geschwindigkeitsregler_DW.DelayInput1_DSTATE_c
	  section.data(2).logicalSrcIdx = 12;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Geschwindigkeitsregler_DW.DelayInput1_DSTATE_o
	  section.data(3).logicalSrcIdx = 13;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Geschwindigkeitsregler_DW.DelayInput1_DSTATE_ol
	  section.data(4).logicalSrcIdx = 14;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_DW.Subsystem1_SubsysRanBC
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Geschwindigkeitsregler_DW.Subsystem2_SubsysRanBC
	  section.data(2).logicalSrcIdx = 16;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_DW.Subsystem3.Delay_DSTATE
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_DW.Subsystem3.Subsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 18;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_DW.Subsystem.Delay_DSTATE
	  section.data(1).logicalSrcIdx = 19;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Geschwindigkeitsregler_DW.Subsystem.Subsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
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


  targMap.checksum0 = 4234395340;
  targMap.checksum1 = 4170173558;
  targMap.checksum2 = 1145180606;
  targMap.checksum3 = 3896224851;

