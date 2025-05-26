  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
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
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (feedback_lin_RLS_Template_201_P)
    ;%
      section.nData     = 23;
      section.data(23)  = dumData; %prealloc
      
	  ;% feedback_lin_RLS_Template_201_P.A_ob
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% feedback_lin_RLS_Template_201_P.B_ob
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 9;
	
	  ;% feedback_lin_RLS_Template_201_P.C_ob
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 18;
	
	  ;% feedback_lin_RLS_Template_201_P.Kb
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 27;
	
	  ;% feedback_lin_RLS_Template_201_P.Lc_mod
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 28;
	
	  ;% feedback_lin_RLS_Template_201_P.Rtot_mod
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 29;
	
	  ;% feedback_lin_RLS_Template_201_P.k_mag
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 30;
	
	  ;% feedback_lin_RLS_Template_201_P.k_mag_mod
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 31;
	
	  ;% feedback_lin_RLS_Template_201_P.m
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 32;
	
	  ;% feedback_lin_RLS_Template_201_P.offset_corrente_volt
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 33;
	
	  ;% feedback_lin_RLS_Template_201_P.offset_posizione_volt
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 34;
	
	  ;% feedback_lin_RLS_Template_201_P.u
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 35;
	
	  ;% feedback_lin_RLS_Template_201_P.x1_eq0
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 36;
	
	  ;% feedback_lin_RLS_Template_201_P.x2_eq0
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 37;
	
	  ;% feedback_lin_RLS_Template_201_P.y0
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 38;
	
	  ;% feedback_lin_RLS_Template_201_P.PIDController_I
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 39;
	
	  ;% feedback_lin_RLS_Template_201_P.PIDController_InitialConditionF
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 40;
	
	  ;% feedback_lin_RLS_Template_201_P.PIDController_P
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 41;
	
	  ;% feedback_lin_RLS_Template_201_P.Subsystem_mu
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 42;
	
	  ;% feedback_lin_RLS_Template_201_P.Subsystem1_mu
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 43;
	
	  ;% feedback_lin_RLS_Template_201_P.Subsystem2_p1
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 44;
	
	  ;% feedback_lin_RLS_Template_201_P.Subsystem2_p2
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 45;
	
	  ;% feedback_lin_RLS_Template_201_P.Subsystem2_p3
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 46;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% feedback_lin_RLS_Template_201_P.BallPositionandCurrent_channels
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
	  ;% feedback_lin_RLS_Template_201_P.Voltage_channels
	  section.data(2).logicalSrcIdx = 24;
	  section.data(2).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 59;
      section.data(59)  = dumData; %prealloc
      
	  ;% feedback_lin_RLS_Template_201_P.Switch_Threshold
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
	  ;% feedback_lin_RLS_Template_201_P.Switch2_Threshold
	  section.data(2).logicalSrcIdx = 26;
	  section.data(2).dtTransOffset = 1;
	
	  ;% feedback_lin_RLS_Template_201_P.HILInitialize_OOTerminate
	  section.data(3).logicalSrcIdx = 27;
	  section.data(3).dtTransOffset = 2;
	
	  ;% feedback_lin_RLS_Template_201_P.HILInitialize_OOExit
	  section.data(4).logicalSrcIdx = 28;
	  section.data(4).dtTransOffset = 3;
	
	  ;% feedback_lin_RLS_Template_201_P.HILInitialize_AOFinal
	  section.data(5).logicalSrcIdx = 29;
	  section.data(5).dtTransOffset = 4;
	
	  ;% feedback_lin_RLS_Template_201_P.HILInitialize_POFinal
	  section.data(6).logicalSrcIdx = 30;
	  section.data(6).dtTransOffset = 5;
	
	  ;% feedback_lin_RLS_Template_201_P.SineWave1_Amp
	  section.data(7).logicalSrcIdx = 31;
	  section.data(7).dtTransOffset = 6;
	
	  ;% feedback_lin_RLS_Template_201_P.SineWave1_Bias
	  section.data(8).logicalSrcIdx = 32;
	  section.data(8).dtTransOffset = 7;
	
	  ;% feedback_lin_RLS_Template_201_P.SineWave1_Freq
	  section.data(9).logicalSrcIdx = 33;
	  section.data(9).dtTransOffset = 8;
	
	  ;% feedback_lin_RLS_Template_201_P.SineWave1_Phase
	  section.data(10).logicalSrcIdx = 34;
	  section.data(10).dtTransOffset = 9;
	
	  ;% feedback_lin_RLS_Template_201_P.Step1_Time
	  section.data(11).logicalSrcIdx = 35;
	  section.data(11).dtTransOffset = 10;
	
	  ;% feedback_lin_RLS_Template_201_P.Step1_Y0
	  section.data(12).logicalSrcIdx = 36;
	  section.data(12).dtTransOffset = 11;
	
	  ;% feedback_lin_RLS_Template_201_P.Step1_YFinal
	  section.data(13).logicalSrcIdx = 37;
	  section.data(13).dtTransOffset = 12;
	
	  ;% feedback_lin_RLS_Template_201_P.SineWave_Amp
	  section.data(14).logicalSrcIdx = 38;
	  section.data(14).dtTransOffset = 13;
	
	  ;% feedback_lin_RLS_Template_201_P.SineWave_Bias
	  section.data(15).logicalSrcIdx = 39;
	  section.data(15).dtTransOffset = 14;
	
	  ;% feedback_lin_RLS_Template_201_P.SineWave_Freq
	  section.data(16).logicalSrcIdx = 40;
	  section.data(16).dtTransOffset = 15;
	
	  ;% feedback_lin_RLS_Template_201_P.SineWave_Phase
	  section.data(17).logicalSrcIdx = 41;
	  section.data(17).dtTransOffset = 16;
	
	  ;% feedback_lin_RLS_Template_201_P.Step_Time
	  section.data(18).logicalSrcIdx = 42;
	  section.data(18).dtTransOffset = 17;
	
	  ;% feedback_lin_RLS_Template_201_P.Step_Y0
	  section.data(19).logicalSrcIdx = 43;
	  section.data(19).dtTransOffset = 18;
	
	  ;% feedback_lin_RLS_Template_201_P.Step_YFinal
	  section.data(20).logicalSrcIdx = 44;
	  section.data(20).dtTransOffset = 19;
	
	  ;% feedback_lin_RLS_Template_201_P.Switch1_Threshold
	  section.data(21).logicalSrcIdx = 45;
	  section.data(21).dtTransOffset = 20;
	
	  ;% feedback_lin_RLS_Template_201_P.TransferFcn_A
	  section.data(22).logicalSrcIdx = 46;
	  section.data(22).dtTransOffset = 21;
	
	  ;% feedback_lin_RLS_Template_201_P.TransferFcn_C
	  section.data(23).logicalSrcIdx = 47;
	  section.data(23).dtTransOffset = 22;
	
	  ;% feedback_lin_RLS_Template_201_P.TransferFcn1_A
	  section.data(24).logicalSrcIdx = 48;
	  section.data(24).dtTransOffset = 23;
	
	  ;% feedback_lin_RLS_Template_201_P.TransferFcn1_C
	  section.data(25).logicalSrcIdx = 49;
	  section.data(25).dtTransOffset = 24;
	
	  ;% feedback_lin_RLS_Template_201_P.TransferFcn2_A
	  section.data(26).logicalSrcIdx = 50;
	  section.data(26).dtTransOffset = 25;
	
	  ;% feedback_lin_RLS_Template_201_P.TransferFcn2_C
	  section.data(27).logicalSrcIdx = 51;
	  section.data(27).dtTransOffset = 26;
	
	  ;% feedback_lin_RLS_Template_201_P.TransferFcn2_D
	  section.data(28).logicalSrcIdx = 52;
	  section.data(28).dtTransOffset = 27;
	
	  ;% feedback_lin_RLS_Template_201_P.TransferFcn_A_g
	  section.data(29).logicalSrcIdx = 53;
	  section.data(29).dtTransOffset = 28;
	
	  ;% feedback_lin_RLS_Template_201_P.TransferFcn_C_b
	  section.data(30).logicalSrcIdx = 54;
	  section.data(30).dtTransOffset = 29;
	
	  ;% feedback_lin_RLS_Template_201_P.TransferFcn_D
	  section.data(31).logicalSrcIdx = 55;
	  section.data(31).dtTransOffset = 30;
	
	  ;% feedback_lin_RLS_Template_201_P.TransferFcn1_A_p
	  section.data(32).logicalSrcIdx = 56;
	  section.data(32).dtTransOffset = 31;
	
	  ;% feedback_lin_RLS_Template_201_P.TransferFcn1_C_b
	  section.data(33).logicalSrcIdx = 57;
	  section.data(33).dtTransOffset = 32;
	
	  ;% feedback_lin_RLS_Template_201_P.TransferFcn1_D
	  section.data(34).logicalSrcIdx = 58;
	  section.data(34).dtTransOffset = 33;
	
	  ;% feedback_lin_RLS_Template_201_P.TransferFcn2_A_k
	  section.data(35).logicalSrcIdx = 59;
	  section.data(35).dtTransOffset = 34;
	
	  ;% feedback_lin_RLS_Template_201_P.TransferFcn2_C_j
	  section.data(36).logicalSrcIdx = 60;
	  section.data(36).dtTransOffset = 35;
	
	  ;% feedback_lin_RLS_Template_201_P.TransferFcn2_D_g
	  section.data(37).logicalSrcIdx = 61;
	  section.data(37).dtTransOffset = 36;
	
	  ;% feedback_lin_RLS_Template_201_P.Delay1_InitialCondition
	  section.data(38).logicalSrcIdx = 62;
	  section.data(38).dtTransOffset = 37;
	
	  ;% feedback_lin_RLS_Template_201_P.Delay1_InitialCondition_o
	  section.data(39).logicalSrcIdx = 63;
	  section.data(39).dtTransOffset = 38;
	
	  ;% feedback_lin_RLS_Template_201_P.Gain_Gain
	  section.data(40).logicalSrcIdx = 64;
	  section.data(40).dtTransOffset = 39;
	
	  ;% feedback_lin_RLS_Template_201_P.Delay2_InitialCondition
	  section.data(41).logicalSrcIdx = 65;
	  section.data(41).dtTransOffset = 40;
	
	  ;% feedback_lin_RLS_Template_201_P.Constant_Value
	  section.data(42).logicalSrcIdx = 66;
	  section.data(42).dtTransOffset = 41;
	
	  ;% feedback_lin_RLS_Template_201_P.Delay3_InitialCondition
	  section.data(43).logicalSrcIdx = 67;
	  section.data(43).dtTransOffset = 42;
	
	  ;% feedback_lin_RLS_Template_201_P.Saturation_UpperSat
	  section.data(44).logicalSrcIdx = 68;
	  section.data(44).dtTransOffset = 45;
	
	  ;% feedback_lin_RLS_Template_201_P.Saturation_LowerSat
	  section.data(45).logicalSrcIdx = 69;
	  section.data(45).dtTransOffset = 46;
	
	  ;% feedback_lin_RLS_Template_201_P.Delay_InitialCondition
	  section.data(46).logicalSrcIdx = 70;
	  section.data(46).dtTransOffset = 47;
	
	  ;% feedback_lin_RLS_Template_201_P.Delay1_InitialCondition_f
	  section.data(47).logicalSrcIdx = 71;
	  section.data(47).dtTransOffset = 49;
	
	  ;% feedback_lin_RLS_Template_201_P.Delay3_InitialCondition_a
	  section.data(48).logicalSrcIdx = 72;
	  section.data(48).dtTransOffset = 53;
	
	  ;% feedback_lin_RLS_Template_201_P.Delay1_InitialCondition_i
	  section.data(49).logicalSrcIdx = 73;
	  section.data(49).dtTransOffset = 54;
	
	  ;% feedback_lin_RLS_Template_201_P.Delay2_InitialCondition_j
	  section.data(50).logicalSrcIdx = 74;
	  section.data(50).dtTransOffset = 55;
	
	  ;% feedback_lin_RLS_Template_201_P.Saturation1_UpperSat
	  section.data(51).logicalSrcIdx = 75;
	  section.data(51).dtTransOffset = 56;
	
	  ;% feedback_lin_RLS_Template_201_P.Saturation1_LowerSat
	  section.data(52).logicalSrcIdx = 76;
	  section.data(52).dtTransOffset = 57;
	
	  ;% feedback_lin_RLS_Template_201_P.Saturation2_UpperSat
	  section.data(53).logicalSrcIdx = 77;
	  section.data(53).dtTransOffset = 58;
	
	  ;% feedback_lin_RLS_Template_201_P.Saturation2_LowerSat
	  section.data(54).logicalSrcIdx = 78;
	  section.data(54).dtTransOffset = 59;
	
	  ;% feedback_lin_RLS_Template_201_P.Constant_Value_d
	  section.data(55).logicalSrcIdx = 79;
	  section.data(55).dtTransOffset = 60;
	
	  ;% feedback_lin_RLS_Template_201_P.Saturation_UpperSat_h
	  section.data(56).logicalSrcIdx = 80;
	  section.data(56).dtTransOffset = 65;
	
	  ;% feedback_lin_RLS_Template_201_P.Saturation_LowerSat_p
	  section.data(57).logicalSrcIdx = 81;
	  section.data(57).dtTransOffset = 66;
	
	  ;% feedback_lin_RLS_Template_201_P.Stateobserver_InitialCondition
	  section.data(58).logicalSrcIdx = 82;
	  section.data(58).dtTransOffset = 67;
	
	  ;% feedback_lin_RLS_Template_201_P.Gain_Gain_h
	  section.data(59).logicalSrcIdx = 83;
	  section.data(59).dtTransOffset = 70;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% feedback_lin_RLS_Template_201_P.ToHostFile_Decimation
	  section.data(1).logicalSrcIdx = 84;
	  section.data(1).dtTransOffset = 0;
	
	  ;% feedback_lin_RLS_Template_201_P.ToHostFile_BitRate
	  section.data(2).logicalSrcIdx = 85;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% feedback_lin_RLS_Template_201_P.HILInitialize_Active
	  section.data(1).logicalSrcIdx = 86;
	  section.data(1).dtTransOffset = 0;
	
	  ;% feedback_lin_RLS_Template_201_P.HILInitialize_AOTerminate
	  section.data(2).logicalSrcIdx = 87;
	  section.data(2).dtTransOffset = 1;
	
	  ;% feedback_lin_RLS_Template_201_P.HILInitialize_AOExit
	  section.data(3).logicalSrcIdx = 88;
	  section.data(3).dtTransOffset = 2;
	
	  ;% feedback_lin_RLS_Template_201_P.HILInitialize_DOTerminate
	  section.data(4).logicalSrcIdx = 89;
	  section.data(4).dtTransOffset = 3;
	
	  ;% feedback_lin_RLS_Template_201_P.HILInitialize_DOExit
	  section.data(5).logicalSrcIdx = 90;
	  section.data(5).dtTransOffset = 4;
	
	  ;% feedback_lin_RLS_Template_201_P.HILInitialize_POTerminate
	  section.data(6).logicalSrcIdx = 91;
	  section.data(6).dtTransOffset = 5;
	
	  ;% feedback_lin_RLS_Template_201_P.HILInitialize_POExit
	  section.data(7).logicalSrcIdx = 92;
	  section.data(7).dtTransOffset = 6;
	
	  ;% feedback_lin_RLS_Template_201_P.HILInitialize_DOFinal
	  section.data(8).logicalSrcIdx = 93;
	  section.data(8).dtTransOffset = 7;
	
	  ;% feedback_lin_RLS_Template_201_P.BallPositionandCurrent_Active
	  section.data(9).logicalSrcIdx = 94;
	  section.data(9).dtTransOffset = 8;
	
	  ;% feedback_lin_RLS_Template_201_P.Voltage_Active
	  section.data(10).logicalSrcIdx = 95;
	  section.data(10).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% feedback_lin_RLS_Template_201_P.ManualSwitch1_CurrentSetting
	  section.data(1).logicalSrcIdx = 96;
	  section.data(1).dtTransOffset = 0;
	
	  ;% feedback_lin_RLS_Template_201_P.ManualSwitch2_CurrentSetting
	  section.data(2).logicalSrcIdx = 97;
	  section.data(2).dtTransOffset = 1;
	
	  ;% feedback_lin_RLS_Template_201_P.ToHostFile_file_name
	  section.data(3).logicalSrcIdx = 98;
	  section.data(3).dtTransOffset = 2;
	
	  ;% feedback_lin_RLS_Template_201_P.ToHostFile_VarName
	  section.data(4).logicalSrcIdx = 99;
	  section.data(4).dtTransOffset = 32;
	
	  ;% feedback_lin_RLS_Template_201_P.ToHostFile_FileFormat
	  section.data(5).logicalSrcIdx = 100;
	  section.data(5).dtTransOffset = 58;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
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
    nTotSects     = 1;
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
    ;% Auto data (feedback_lin_RLS_Template_201_B)
    ;%
      section.nData     = 27;
      section.data(27)  = dumData; %prealloc
      
	  ;% feedback_lin_RLS_Template_201_B.corrente
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% feedback_lin_RLS_Template_201_B.Switch1
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% feedback_lin_RLS_Template_201_B.posizione
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% feedback_lin_RLS_Template_201_B.ManualSwitch1
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% feedback_lin_RLS_Template_201_B.ManualSwitch2
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% feedback_lin_RLS_Template_201_B.TransferFcn2
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% feedback_lin_RLS_Template_201_B.TransferFcn
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% feedback_lin_RLS_Template_201_B.TransferFcn1
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% feedback_lin_RLS_Template_201_B.TransferFcn2_a
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% feedback_lin_RLS_Template_201_B.Saturation
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% feedback_lin_RLS_Template_201_B.TmpSignalConversionAtStateobser
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% feedback_lin_RLS_Template_201_B.Gain
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 13;
	
	  ;% feedback_lin_RLS_Template_201_B.IntegralGain
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 14;
	
	  ;% feedback_lin_RLS_Template_201_B.Constant
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 15;
	
	  ;% feedback_lin_RLS_Template_201_B.Constant1
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 16;
	
	  ;% feedback_lin_RLS_Template_201_B.Constant2
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 17;
	
	  ;% feedback_lin_RLS_Template_201_B.R
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 18;
	
	  ;% feedback_lin_RLS_Template_201_B.Lc
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 19;
	
	  ;% feedback_lin_RLS_Template_201_B.tho
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 20;
	
	  ;% feedback_lin_RLS_Template_201_B.Vo
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 22;
	
	  ;% feedback_lin_RLS_Template_201_B.k_mag
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 26;
	
	  ;% feedback_lin_RLS_Template_201_B.tho_g
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 27;
	
	  ;% feedback_lin_RLS_Template_201_B.Vo_g
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 28;
	
	  ;% feedback_lin_RLS_Template_201_B.theta
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 29;
	
	  ;% feedback_lin_RLS_Template_201_B.K
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 35;
	
	  ;% feedback_lin_RLS_Template_201_B.beta
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 38;
	
	  ;% feedback_lin_RLS_Template_201_B.x3_hat
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 39;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
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
    nTotSects     = 5;
    sectIdxOffset = 1;
    
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
    ;% Auto data (feedback_lin_RLS_Template_20_DW)
    ;%
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% feedback_lin_RLS_Template_20_DW.Delay_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% feedback_lin_RLS_Template_20_DW.Delay1_DSTATE
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_p
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% feedback_lin_RLS_Template_20_DW.Delay2_DSTATE
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% feedback_lin_RLS_Template_20_DW.Delay3_DSTATE
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% feedback_lin_RLS_Template_20_DW.Delay_DSTATE_d
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 7;
	
	  ;% feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_f
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 9;
	
	  ;% feedback_lin_RLS_Template_20_DW.Delay3_DSTATE_b
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 13;
	
	  ;% feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_a
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 14;
	
	  ;% feedback_lin_RLS_Template_20_DW.Delay2_DSTATE_h
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 17;
	
	  ;% feedback_lin_RLS_Template_20_DW.HILInitialize_AOVoltages
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 18;
	
	  ;% feedback_lin_RLS_Template_20_DW.BallPositionandCurrent_Buffer
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 20;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% feedback_lin_RLS_Template_20_DW.ToHostFile_PointsWritten
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% feedback_lin_RLS_Template_20_DW.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 13;
      section.data(13)  = dumData; %prealloc
      
	  ;% feedback_lin_RLS_Template_20_DW.BallPositionandCurrent_PWORK
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
	  ;% feedback_lin_RLS_Template_20_DW.Scope_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 15;
	  section.data(2).dtTransOffset = 1;
	
	  ;% feedback_lin_RLS_Template_20_DW.Scope1_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 16;
	  section.data(3).dtTransOffset = 2;
	
	  ;% feedback_lin_RLS_Template_20_DW.Scope2_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 17;
	  section.data(4).dtTransOffset = 4;
	
	  ;% feedback_lin_RLS_Template_20_DW.ToHostFile_PWORK
	  section.data(5).logicalSrcIdx = 18;
	  section.data(5).dtTransOffset = 5;
	
	  ;% feedback_lin_RLS_Template_20_DW.Scope_PWORK_e.LoggedData
	  section.data(6).logicalSrcIdx = 19;
	  section.data(6).dtTransOffset = 7;
	
	  ;% feedback_lin_RLS_Template_20_DW.Scope1_PWORK_a.LoggedData
	  section.data(7).logicalSrcIdx = 20;
	  section.data(7).dtTransOffset = 9;
	
	  ;% feedback_lin_RLS_Template_20_DW.Voltage_PWORK
	  section.data(8).logicalSrcIdx = 21;
	  section.data(8).dtTransOffset = 11;
	
	  ;% feedback_lin_RLS_Template_20_DW.Scope_PWORK_m.LoggedData
	  section.data(9).logicalSrcIdx = 22;
	  section.data(9).dtTransOffset = 12;
	
	  ;% feedback_lin_RLS_Template_20_DW.Scope1_PWORK_b.LoggedData
	  section.data(10).logicalSrcIdx = 23;
	  section.data(10).dtTransOffset = 13;
	
	  ;% feedback_lin_RLS_Template_20_DW.Scope_PWORK_mr.LoggedData
	  section.data(11).logicalSrcIdx = 24;
	  section.data(11).dtTransOffset = 17;
	
	  ;% feedback_lin_RLS_Template_20_DW.Scope1_PWORK_b2.LoggedData
	  section.data(12).logicalSrcIdx = 25;
	  section.data(12).dtTransOffset = 19;
	
	  ;% feedback_lin_RLS_Template_20_DW.Scope2_PWORK_d.LoggedData
	  section.data(13).logicalSrcIdx = 26;
	  section.data(13).dtTransOffset = 21;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% feedback_lin_RLS_Template_20_DW.ToHostFile_SamplesCount
	  section.data(1).logicalSrcIdx = 27;
	  section.data(1).dtTransOffset = 0;
	
	  ;% feedback_lin_RLS_Template_20_DW.ToHostFile_ArrayNameLength
	  section.data(2).logicalSrcIdx = 28;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
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


  targMap.checksum0 = 1051783073;
  targMap.checksum1 = 3936676692;
  targMap.checksum2 = 1987929828;
  targMap.checksum3 = 1925087470;

