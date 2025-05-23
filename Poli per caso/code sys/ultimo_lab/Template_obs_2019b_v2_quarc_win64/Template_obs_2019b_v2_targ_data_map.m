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
    ;% Auto data (Template_obs_2019b_v2_P)
    ;%
      section.nData     = 13;
      section.data(13)  = dumData; %prealloc
      
	  ;% Template_obs_2019b_v2_P.A_ob
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Template_obs_2019b_v2_P.B_ob
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 9;
	
	  ;% Template_obs_2019b_v2_P.C_ob
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 18;
	
	  ;% Template_obs_2019b_v2_P.Kb
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 27;
	
	  ;% Template_obs_2019b_v2_P.Ken_eta
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 28;
	
	  ;% Template_obs_2019b_v2_P.Ken_x
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 29;
	
	  ;% Template_obs_2019b_v2_P.offset_corrente_volt
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 32;
	
	  ;% Template_obs_2019b_v2_P.offset_posizione_volt
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 33;
	
	  ;% Template_obs_2019b_v2_P.u
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 34;
	
	  ;% Template_obs_2019b_v2_P.x1_eq0
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 35;
	
	  ;% Template_obs_2019b_v2_P.x2_eq0
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 36;
	
	  ;% Template_obs_2019b_v2_P.BandLimitedWhiteNoise_Cov
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 37;
	
	  ;% Template_obs_2019b_v2_P.BandLimitedWhiteNoise_seed
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 38;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Template_obs_2019b_v2_P.BallPositionandCurrent_channels
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Template_obs_2019b_v2_P.Voltage_channels
	  section.data(2).logicalSrcIdx = 14;
	  section.data(2).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 56;
      section.data(56)  = dumData; %prealloc
      
	  ;% Template_obs_2019b_v2_P.Switch_Threshold
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Template_obs_2019b_v2_P.Switch_Threshold_f
	  section.data(2).logicalSrcIdx = 16;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Template_obs_2019b_v2_P.HILInitialize_OOTerminate
	  section.data(3).logicalSrcIdx = 17;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Template_obs_2019b_v2_P.HILInitialize_OOExit
	  section.data(4).logicalSrcIdx = 18;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Template_obs_2019b_v2_P.HILInitialize_AOFinal
	  section.data(5).logicalSrcIdx = 19;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Template_obs_2019b_v2_P.HILInitialize_POFinal
	  section.data(6).logicalSrcIdx = 20;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Template_obs_2019b_v2_P.Integrator_IC
	  section.data(7).logicalSrcIdx = 21;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Template_obs_2019b_v2_P.StateSpace_InitialCondition
	  section.data(8).logicalSrcIdx = 22;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Template_obs_2019b_v2_P.TransferFcn_A
	  section.data(9).logicalSrcIdx = 23;
	  section.data(9).dtTransOffset = 10;
	
	  ;% Template_obs_2019b_v2_P.TransferFcn_C
	  section.data(10).logicalSrcIdx = 24;
	  section.data(10).dtTransOffset = 11;
	
	  ;% Template_obs_2019b_v2_P.TransferFcn1_A
	  section.data(11).logicalSrcIdx = 25;
	  section.data(11).dtTransOffset = 12;
	
	  ;% Template_obs_2019b_v2_P.TransferFcn1_C
	  section.data(12).logicalSrcIdx = 26;
	  section.data(12).dtTransOffset = 13;
	
	  ;% Template_obs_2019b_v2_P.Step_Time
	  section.data(13).logicalSrcIdx = 27;
	  section.data(13).dtTransOffset = 14;
	
	  ;% Template_obs_2019b_v2_P.Step_Y0
	  section.data(14).logicalSrcIdx = 28;
	  section.data(14).dtTransOffset = 15;
	
	  ;% Template_obs_2019b_v2_P.Step_YFinal
	  section.data(15).logicalSrcIdx = 29;
	  section.data(15).dtTransOffset = 16;
	
	  ;% Template_obs_2019b_v2_P.SineWave_Amp
	  section.data(16).logicalSrcIdx = 30;
	  section.data(16).dtTransOffset = 17;
	
	  ;% Template_obs_2019b_v2_P.SineWave_Bias
	  section.data(17).logicalSrcIdx = 31;
	  section.data(17).dtTransOffset = 18;
	
	  ;% Template_obs_2019b_v2_P.SineWave_Freq
	  section.data(18).logicalSrcIdx = 32;
	  section.data(18).dtTransOffset = 19;
	
	  ;% Template_obs_2019b_v2_P.SineWave_Hsin
	  section.data(19).logicalSrcIdx = 33;
	  section.data(19).dtTransOffset = 20;
	
	  ;% Template_obs_2019b_v2_P.SineWave_HCos
	  section.data(20).logicalSrcIdx = 34;
	  section.data(20).dtTransOffset = 21;
	
	  ;% Template_obs_2019b_v2_P.SineWave_PSin
	  section.data(21).logicalSrcIdx = 35;
	  section.data(21).dtTransOffset = 22;
	
	  ;% Template_obs_2019b_v2_P.SineWave_PCos
	  section.data(22).logicalSrcIdx = 36;
	  section.data(22).dtTransOffset = 23;
	
	  ;% Template_obs_2019b_v2_P.SineWave_Amp_g
	  section.data(23).logicalSrcIdx = 37;
	  section.data(23).dtTransOffset = 24;
	
	  ;% Template_obs_2019b_v2_P.SineWave_Bias_f
	  section.data(24).logicalSrcIdx = 38;
	  section.data(24).dtTransOffset = 25;
	
	  ;% Template_obs_2019b_v2_P.SineWave_Freq_o
	  section.data(25).logicalSrcIdx = 39;
	  section.data(25).dtTransOffset = 26;
	
	  ;% Template_obs_2019b_v2_P.SineWave_Hsin_d
	  section.data(26).logicalSrcIdx = 40;
	  section.data(26).dtTransOffset = 27;
	
	  ;% Template_obs_2019b_v2_P.SineWave_HCos_d
	  section.data(27).logicalSrcIdx = 41;
	  section.data(27).dtTransOffset = 28;
	
	  ;% Template_obs_2019b_v2_P.SineWave_PSin_a
	  section.data(28).logicalSrcIdx = 42;
	  section.data(28).dtTransOffset = 29;
	
	  ;% Template_obs_2019b_v2_P.SineWave_PCos_h
	  section.data(29).logicalSrcIdx = 43;
	  section.data(29).dtTransOffset = 30;
	
	  ;% Template_obs_2019b_v2_P.Step_Time_c
	  section.data(30).logicalSrcIdx = 44;
	  section.data(30).dtTransOffset = 31;
	
	  ;% Template_obs_2019b_v2_P.Step_Y0_a
	  section.data(31).logicalSrcIdx = 45;
	  section.data(31).dtTransOffset = 32;
	
	  ;% Template_obs_2019b_v2_P.Step_YFinal_c
	  section.data(32).logicalSrcIdx = 46;
	  section.data(32).dtTransOffset = 33;
	
	  ;% Template_obs_2019b_v2_P.Step1_Time
	  section.data(33).logicalSrcIdx = 47;
	  section.data(33).dtTransOffset = 34;
	
	  ;% Template_obs_2019b_v2_P.Step1_Y0
	  section.data(34).logicalSrcIdx = 48;
	  section.data(34).dtTransOffset = 35;
	
	  ;% Template_obs_2019b_v2_P.Step1_YFinal
	  section.data(35).logicalSrcIdx = 49;
	  section.data(35).dtTransOffset = 36;
	
	  ;% Template_obs_2019b_v2_P.Step2_Time
	  section.data(36).logicalSrcIdx = 50;
	  section.data(36).dtTransOffset = 37;
	
	  ;% Template_obs_2019b_v2_P.Step2_Y0
	  section.data(37).logicalSrcIdx = 51;
	  section.data(37).dtTransOffset = 38;
	
	  ;% Template_obs_2019b_v2_P.Step2_YFinal
	  section.data(38).logicalSrcIdx = 52;
	  section.data(38).dtTransOffset = 39;
	
	  ;% Template_obs_2019b_v2_P.TransferFcn2_A
	  section.data(39).logicalSrcIdx = 53;
	  section.data(39).dtTransOffset = 40;
	
	  ;% Template_obs_2019b_v2_P.TransferFcn2_C
	  section.data(40).logicalSrcIdx = 54;
	  section.data(40).dtTransOffset = 41;
	
	  ;% Template_obs_2019b_v2_P.TransferFcn3_A
	  section.data(41).logicalSrcIdx = 55;
	  section.data(41).dtTransOffset = 42;
	
	  ;% Template_obs_2019b_v2_P.TransferFcn3_C
	  section.data(42).logicalSrcIdx = 56;
	  section.data(42).dtTransOffset = 43;
	
	  ;% Template_obs_2019b_v2_P.TransferFcn1_A_g
	  section.data(43).logicalSrcIdx = 57;
	  section.data(43).dtTransOffset = 44;
	
	  ;% Template_obs_2019b_v2_P.TransferFcn1_C_m
	  section.data(44).logicalSrcIdx = 58;
	  section.data(44).dtTransOffset = 45;
	
	  ;% Template_obs_2019b_v2_P.TransferFcn1_D
	  section.data(45).logicalSrcIdx = 59;
	  section.data(45).dtTransOffset = 46;
	
	  ;% Template_obs_2019b_v2_P.WhiteNoise_Mean
	  section.data(46).logicalSrcIdx = 60;
	  section.data(46).dtTransOffset = 47;
	
	  ;% Template_obs_2019b_v2_P.WhiteNoise_StdDev
	  section.data(47).logicalSrcIdx = 61;
	  section.data(47).dtTransOffset = 48;
	
	  ;% Template_obs_2019b_v2_P.TransferFcn4_A
	  section.data(48).logicalSrcIdx = 62;
	  section.data(48).dtTransOffset = 49;
	
	  ;% Template_obs_2019b_v2_P.TransferFcn4_C
	  section.data(49).logicalSrcIdx = 63;
	  section.data(49).dtTransOffset = 50;
	
	  ;% Template_obs_2019b_v2_P.Saturation_UpperSat
	  section.data(50).logicalSrcIdx = 64;
	  section.data(50).dtTransOffset = 51;
	
	  ;% Template_obs_2019b_v2_P.Saturation_LowerSat
	  section.data(51).logicalSrcIdx = 65;
	  section.data(51).dtTransOffset = 52;
	
	  ;% Template_obs_2019b_v2_P.Gain_Gain
	  section.data(52).logicalSrcIdx = 66;
	  section.data(52).dtTransOffset = 53;
	
	  ;% Template_obs_2019b_v2_P.TransferFcn_A_c
	  section.data(53).logicalSrcIdx = 67;
	  section.data(53).dtTransOffset = 54;
	
	  ;% Template_obs_2019b_v2_P.TransferFcn_C_e
	  section.data(54).logicalSrcIdx = 68;
	  section.data(54).dtTransOffset = 55;
	
	  ;% Template_obs_2019b_v2_P.TransferFcn1_A_c
	  section.data(55).logicalSrcIdx = 69;
	  section.data(55).dtTransOffset = 56;
	
	  ;% Template_obs_2019b_v2_P.TransferFcn1_C_f
	  section.data(56).logicalSrcIdx = 70;
	  section.data(56).dtTransOffset = 57;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Template_obs_2019b_v2_P.ToHostFile_Decimation
	  section.data(1).logicalSrcIdx = 71;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Template_obs_2019b_v2_P.ToHostFile_BitRate
	  section.data(2).logicalSrcIdx = 72;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% Template_obs_2019b_v2_P.HILInitialize_Active
	  section.data(1).logicalSrcIdx = 73;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Template_obs_2019b_v2_P.HILInitialize_AOTerminate
	  section.data(2).logicalSrcIdx = 74;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Template_obs_2019b_v2_P.HILInitialize_AOExit
	  section.data(3).logicalSrcIdx = 75;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Template_obs_2019b_v2_P.HILInitialize_DOTerminate
	  section.data(4).logicalSrcIdx = 76;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Template_obs_2019b_v2_P.HILInitialize_DOExit
	  section.data(5).logicalSrcIdx = 77;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Template_obs_2019b_v2_P.HILInitialize_POTerminate
	  section.data(6).logicalSrcIdx = 78;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Template_obs_2019b_v2_P.HILInitialize_POExit
	  section.data(7).logicalSrcIdx = 79;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Template_obs_2019b_v2_P.HILInitialize_DOFinal
	  section.data(8).logicalSrcIdx = 80;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Template_obs_2019b_v2_P.BallPositionandCurrent_Active
	  section.data(9).logicalSrcIdx = 81;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Template_obs_2019b_v2_P.Voltage_Active
	  section.data(10).logicalSrcIdx = 82;
	  section.data(10).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 14;
      section.data(14)  = dumData; %prealloc
      
	  ;% Template_obs_2019b_v2_P.ManualSwitch_CurrentSetting
	  section.data(1).logicalSrcIdx = 83;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Template_obs_2019b_v2_P.ManualSwitch1_CurrentSetting
	  section.data(2).logicalSrcIdx = 84;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Template_obs_2019b_v2_P.ManualSwitch2_CurrentSetting
	  section.data(3).logicalSrcIdx = 85;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Template_obs_2019b_v2_P.ManualSwitch_CurrentSetting_i
	  section.data(4).logicalSrcIdx = 86;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Template_obs_2019b_v2_P.ManualSwitch1_CurrentSetting_m
	  section.data(5).logicalSrcIdx = 87;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Template_obs_2019b_v2_P.ManualSwitch5_CurrentSetting
	  section.data(6).logicalSrcIdx = 88;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Template_obs_2019b_v2_P.ManualSwitch6_CurrentSetting
	  section.data(7).logicalSrcIdx = 89;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Template_obs_2019b_v2_P.ToHostFile_file_name
	  section.data(8).logicalSrcIdx = 90;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Template_obs_2019b_v2_P.ToHostFile_VarName
	  section.data(9).logicalSrcIdx = 91;
	  section.data(9).dtTransOffset = 37;
	
	  ;% Template_obs_2019b_v2_P.ToHostFile_FileFormat
	  section.data(10).logicalSrcIdx = 92;
	  section.data(10).dtTransOffset = 63;
	
	  ;% Template_obs_2019b_v2_P.ManualSwitch3_CurrentSetting
	  section.data(11).logicalSrcIdx = 93;
	  section.data(11).dtTransOffset = 64;
	
	  ;% Template_obs_2019b_v2_P.ManualSwitch2_CurrentSetting_n
	  section.data(12).logicalSrcIdx = 94;
	  section.data(12).dtTransOffset = 65;
	
	  ;% Template_obs_2019b_v2_P.ManualSwitch_CurrentSetting_l
	  section.data(13).logicalSrcIdx = 95;
	  section.data(13).dtTransOffset = 66;
	
	  ;% Template_obs_2019b_v2_P.ManualSwitch1_CurrentSetting_n
	  section.data(14).logicalSrcIdx = 96;
	  section.data(14).dtTransOffset = 67;
	
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
    ;% Auto data (Template_obs_2019b_v2_B)
    ;%
      section.nData     = 20;
      section.data(20)  = dumData; %prealloc
      
	  ;% Template_obs_2019b_v2_B.StateSpace
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Template_obs_2019b_v2_B.posizione
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3;
	
	  ;% Template_obs_2019b_v2_B.corrente
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 4;
	
	  ;% Template_obs_2019b_v2_B.Sum2
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 5;
	
	  ;% Template_obs_2019b_v2_B.Sum
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 6;
	
	  ;% Template_obs_2019b_v2_B.Step
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 7;
	
	  ;% Template_obs_2019b_v2_B.SineWave
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 8;
	
	  ;% Template_obs_2019b_v2_B.SineWave_b
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 9;
	
	  ;% Template_obs_2019b_v2_B.ManualSwitch1
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 10;
	
	  ;% Template_obs_2019b_v2_B.x1
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 11;
	
	  ;% Template_obs_2019b_v2_B.ManualSwitch5
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 12;
	
	  ;% Template_obs_2019b_v2_B.x1_h
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 13;
	
	  ;% Template_obs_2019b_v2_B.ManualSwitch6
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 14;
	
	  ;% Template_obs_2019b_v2_B.TransferFcn1
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 15;
	
	  ;% Template_obs_2019b_v2_B.Output
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 16;
	
	  ;% Template_obs_2019b_v2_B.Gain
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 17;
	
	  ;% Template_obs_2019b_v2_B.pos_filtro
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 18;
	
	  ;% Template_obs_2019b_v2_B.coorr_filtro
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 19;
	
	  ;% Template_obs_2019b_v2_B.TmpSignalConversionAtStateSpace
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 20;
	
	  ;% Template_obs_2019b_v2_B.Sum1
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 23;
	
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
    nTotSects     = 6;
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
    ;% Auto data (Template_obs_2019b_v2_DW)
    ;%
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% Template_obs_2019b_v2_DW.HILInitialize_AOVoltages
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Template_obs_2019b_v2_DW.BallPositionandCurrent_Buffer
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% Template_obs_2019b_v2_DW.lastSin
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 4;
	
	  ;% Template_obs_2019b_v2_DW.lastCos
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 5;
	
	  ;% Template_obs_2019b_v2_DW.lastSin_b
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 6;
	
	  ;% Template_obs_2019b_v2_DW.lastCos_n
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 7;
	
	  ;% Template_obs_2019b_v2_DW.NextOutput
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Template_obs_2019b_v2_DW.ToHostFile_PointsWritten
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Template_obs_2019b_v2_DW.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% Template_obs_2019b_v2_DW.BallPositionandCurrent_PWORK
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Template_obs_2019b_v2_DW.Scope_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 10;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Template_obs_2019b_v2_DW.Scope1_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 11;
	  section.data(3).dtTransOffset = 3;
	
	  ;% Template_obs_2019b_v2_DW.Scope2_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 12;
	  section.data(4).dtTransOffset = 4;
	
	  ;% Template_obs_2019b_v2_DW.Scope4_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 13;
	  section.data(5).dtTransOffset = 6;
	
	  ;% Template_obs_2019b_v2_DW.Scope5_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 14;
	  section.data(6).dtTransOffset = 8;
	
	  ;% Template_obs_2019b_v2_DW.Scope6_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 15;
	  section.data(7).dtTransOffset = 10;
	
	  ;% Template_obs_2019b_v2_DW.ToHostFile_PWORK
	  section.data(8).logicalSrcIdx = 16;
	  section.data(8).dtTransOffset = 12;
	
	  ;% Template_obs_2019b_v2_DW.Voltage_PWORK
	  section.data(9).logicalSrcIdx = 17;
	  section.data(9).dtTransOffset = 14;
	
	  ;% Template_obs_2019b_v2_DW.Scope_PWORK_h.LoggedData
	  section.data(10).logicalSrcIdx = 18;
	  section.data(10).dtTransOffset = 15;
	
	  ;% Template_obs_2019b_v2_DW.Scope1_PWORK_f.LoggedData
	  section.data(11).logicalSrcIdx = 19;
	  section.data(11).dtTransOffset = 17;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Template_obs_2019b_v2_DW.systemEnable
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Template_obs_2019b_v2_DW.systemEnable_p
	  section.data(2).logicalSrcIdx = 21;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Template_obs_2019b_v2_DW.ToHostFile_SamplesCount
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Template_obs_2019b_v2_DW.ToHostFile_ArrayNameLength
	  section.data(2).logicalSrcIdx = 23;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Template_obs_2019b_v2_DW.RandSeed
	  section.data(3).logicalSrcIdx = 24;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
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


  targMap.checksum0 = 4107523148;
  targMap.checksum1 = 2372171215;
  targMap.checksum2 = 3485923100;
  targMap.checksum3 = 3830480280;

