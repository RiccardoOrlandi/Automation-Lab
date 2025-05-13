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
    ;% Auto data (MagneticLevitation_Template_P)
    ;%
      section.nData     = 14;
      section.data(14)  = dumData; %prealloc
      
	  ;% MagneticLevitation_Template_P.A_ob
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% MagneticLevitation_Template_P.B_ob
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 9;
	
	  ;% MagneticLevitation_Template_P.C_ob
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 18;
	
	  ;% MagneticLevitation_Template_P.Kb
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 27;
	
	  ;% MagneticLevitation_Template_P.Ken_eta
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 28;
	
	  ;% MagneticLevitation_Template_P.Ken_x
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 29;
	
	  ;% MagneticLevitation_Template_P.Upper_bound_V
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 32;
	
	  ;% MagneticLevitation_Template_P.offset_corrente_volt
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 33;
	
	  ;% MagneticLevitation_Template_P.offset_posizione_volt
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 34;
	
	  ;% MagneticLevitation_Template_P.u
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 35;
	
	  ;% MagneticLevitation_Template_P.x1_eq0
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 36;
	
	  ;% MagneticLevitation_Template_P.x2_eq0
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 37;
	
	  ;% MagneticLevitation_Template_P.BandLimitedWhiteNoise_Cov
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 38;
	
	  ;% MagneticLevitation_Template_P.BandLimitedWhiteNoise_seed
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 39;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% MagneticLevitation_Template_P.BallPositionandCurrent_channels
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
	  ;% MagneticLevitation_Template_P.Voltage_channels
	  section.data(2).logicalSrcIdx = 15;
	  section.data(2).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 29;
      section.data(29)  = dumData; %prealloc
      
	  ;% MagneticLevitation_Template_P.HILInitialize_OOTerminate
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
	  ;% MagneticLevitation_Template_P.HILInitialize_OOExit
	  section.data(2).logicalSrcIdx = 17;
	  section.data(2).dtTransOffset = 1;
	
	  ;% MagneticLevitation_Template_P.HILInitialize_AOFinal
	  section.data(3).logicalSrcIdx = 18;
	  section.data(3).dtTransOffset = 2;
	
	  ;% MagneticLevitation_Template_P.HILInitialize_POFinal
	  section.data(4).logicalSrcIdx = 19;
	  section.data(4).dtTransOffset = 3;
	
	  ;% MagneticLevitation_Template_P.Integrator2_IC
	  section.data(5).logicalSrcIdx = 20;
	  section.data(5).dtTransOffset = 4;
	
	  ;% MagneticLevitation_Template_P.StateSpace_InitialCondition
	  section.data(6).logicalSrcIdx = 21;
	  section.data(6).dtTransOffset = 5;
	
	  ;% MagneticLevitation_Template_P.TransferFcn_A
	  section.data(7).logicalSrcIdx = 22;
	  section.data(7).dtTransOffset = 8;
	
	  ;% MagneticLevitation_Template_P.TransferFcn_C
	  section.data(8).logicalSrcIdx = 23;
	  section.data(8).dtTransOffset = 9;
	
	  ;% MagneticLevitation_Template_P.TransferFcn1_A
	  section.data(9).logicalSrcIdx = 24;
	  section.data(9).dtTransOffset = 10;
	
	  ;% MagneticLevitation_Template_P.TransferFcn1_C
	  section.data(10).logicalSrcIdx = 25;
	  section.data(10).dtTransOffset = 11;
	
	  ;% MagneticLevitation_Template_P.Saturation_LowerSat
	  section.data(11).logicalSrcIdx = 26;
	  section.data(11).dtTransOffset = 12;
	
	  ;% MagneticLevitation_Template_P.WhiteNoise_Mean
	  section.data(12).logicalSrcIdx = 27;
	  section.data(12).dtTransOffset = 13;
	
	  ;% MagneticLevitation_Template_P.WhiteNoise_StdDev
	  section.data(13).logicalSrcIdx = 28;
	  section.data(13).dtTransOffset = 14;
	
	  ;% MagneticLevitation_Template_P.SineWave_Amp
	  section.data(14).logicalSrcIdx = 29;
	  section.data(14).dtTransOffset = 15;
	
	  ;% MagneticLevitation_Template_P.SineWave_Bias
	  section.data(15).logicalSrcIdx = 30;
	  section.data(15).dtTransOffset = 16;
	
	  ;% MagneticLevitation_Template_P.SineWave_Freq
	  section.data(16).logicalSrcIdx = 31;
	  section.data(16).dtTransOffset = 17;
	
	  ;% MagneticLevitation_Template_P.SineWave_Phase
	  section.data(17).logicalSrcIdx = 32;
	  section.data(17).dtTransOffset = 18;
	
	  ;% MagneticLevitation_Template_P.Constant_Value
	  section.data(18).logicalSrcIdx = 33;
	  section.data(18).dtTransOffset = 19;
	
	  ;% MagneticLevitation_Template_P.Step_Time
	  section.data(19).logicalSrcIdx = 34;
	  section.data(19).dtTransOffset = 20;
	
	  ;% MagneticLevitation_Template_P.Step_Y0
	  section.data(20).logicalSrcIdx = 35;
	  section.data(20).dtTransOffset = 21;
	
	  ;% MagneticLevitation_Template_P.Step_YFinal
	  section.data(21).logicalSrcIdx = 36;
	  section.data(21).dtTransOffset = 22;
	
	  ;% MagneticLevitation_Template_P.SineWave1_Amp
	  section.data(22).logicalSrcIdx = 37;
	  section.data(22).dtTransOffset = 23;
	
	  ;% MagneticLevitation_Template_P.SineWave1_Bias
	  section.data(23).logicalSrcIdx = 38;
	  section.data(23).dtTransOffset = 24;
	
	  ;% MagneticLevitation_Template_P.SineWave1_Freq
	  section.data(24).logicalSrcIdx = 39;
	  section.data(24).dtTransOffset = 25;
	
	  ;% MagneticLevitation_Template_P.SineWave1_Phase
	  section.data(25).logicalSrcIdx = 40;
	  section.data(25).dtTransOffset = 26;
	
	  ;% MagneticLevitation_Template_P.TransferFcn_A_o
	  section.data(26).logicalSrcIdx = 41;
	  section.data(26).dtTransOffset = 27;
	
	  ;% MagneticLevitation_Template_P.TransferFcn_C_i
	  section.data(27).logicalSrcIdx = 42;
	  section.data(27).dtTransOffset = 28;
	
	  ;% MagneticLevitation_Template_P.TransferFcn_D
	  section.data(28).logicalSrcIdx = 43;
	  section.data(28).dtTransOffset = 29;
	
	  ;% MagneticLevitation_Template_P.Gain_Gain
	  section.data(29).logicalSrcIdx = 44;
	  section.data(29).dtTransOffset = 30;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% MagneticLevitation_Template_P.ToHostFile_Decimation
	  section.data(1).logicalSrcIdx = 45;
	  section.data(1).dtTransOffset = 0;
	
	  ;% MagneticLevitation_Template_P.ToHostFile_BitRate
	  section.data(2).logicalSrcIdx = 46;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% MagneticLevitation_Template_P.HILInitialize_Active
	  section.data(1).logicalSrcIdx = 47;
	  section.data(1).dtTransOffset = 0;
	
	  ;% MagneticLevitation_Template_P.HILInitialize_AOTerminate
	  section.data(2).logicalSrcIdx = 48;
	  section.data(2).dtTransOffset = 1;
	
	  ;% MagneticLevitation_Template_P.HILInitialize_AOExit
	  section.data(3).logicalSrcIdx = 49;
	  section.data(3).dtTransOffset = 2;
	
	  ;% MagneticLevitation_Template_P.HILInitialize_DOTerminate
	  section.data(4).logicalSrcIdx = 50;
	  section.data(4).dtTransOffset = 3;
	
	  ;% MagneticLevitation_Template_P.HILInitialize_DOExit
	  section.data(5).logicalSrcIdx = 51;
	  section.data(5).dtTransOffset = 4;
	
	  ;% MagneticLevitation_Template_P.HILInitialize_POTerminate
	  section.data(6).logicalSrcIdx = 52;
	  section.data(6).dtTransOffset = 5;
	
	  ;% MagneticLevitation_Template_P.HILInitialize_POExit
	  section.data(7).logicalSrcIdx = 53;
	  section.data(7).dtTransOffset = 6;
	
	  ;% MagneticLevitation_Template_P.HILInitialize_DOFinal
	  section.data(8).logicalSrcIdx = 54;
	  section.data(8).dtTransOffset = 7;
	
	  ;% MagneticLevitation_Template_P.BallPositionandCurrent_Active
	  section.data(9).logicalSrcIdx = 55;
	  section.data(9).dtTransOffset = 8;
	
	  ;% MagneticLevitation_Template_P.Voltage_Active
	  section.data(10).logicalSrcIdx = 56;
	  section.data(10).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% MagneticLevitation_Template_P.ManualSwitch3_CurrentSetting
	  section.data(1).logicalSrcIdx = 57;
	  section.data(1).dtTransOffset = 0;
	
	  ;% MagneticLevitation_Template_P.ManualSwitch_CurrentSetting
	  section.data(2).logicalSrcIdx = 58;
	  section.data(2).dtTransOffset = 1;
	
	  ;% MagneticLevitation_Template_P.ManualSwitch1_CurrentSetting
	  section.data(3).logicalSrcIdx = 59;
	  section.data(3).dtTransOffset = 2;
	
	  ;% MagneticLevitation_Template_P.ManualSwitch2_CurrentSetting
	  section.data(4).logicalSrcIdx = 60;
	  section.data(4).dtTransOffset = 3;
	
	  ;% MagneticLevitation_Template_P.ManualSwitch_CurrentSetting_d
	  section.data(5).logicalSrcIdx = 61;
	  section.data(5).dtTransOffset = 4;
	
	  ;% MagneticLevitation_Template_P.ManualSwitch2_CurrentSetting_f
	  section.data(6).logicalSrcIdx = 62;
	  section.data(6).dtTransOffset = 5;
	
	  ;% MagneticLevitation_Template_P.ManualSwitch4_CurrentSetting
	  section.data(7).logicalSrcIdx = 63;
	  section.data(7).dtTransOffset = 6;
	
	  ;% MagneticLevitation_Template_P.ToHostFile_file_name
	  section.data(8).logicalSrcIdx = 64;
	  section.data(8).dtTransOffset = 7;
	
	  ;% MagneticLevitation_Template_P.ToHostFile_VarName
	  section.data(9).logicalSrcIdx = 65;
	  section.data(9).dtTransOffset = 37;
	
	  ;% MagneticLevitation_Template_P.ToHostFile_FileFormat
	  section.data(10).logicalSrcIdx = 66;
	  section.data(10).dtTransOffset = 63;
	
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
    ;% Auto data (MagneticLevitation_Template_B)
    ;%
      section.nData     = 15;
      section.data(15)  = dumData; %prealloc
      
	  ;% MagneticLevitation_Template_B.StateSpace
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% MagneticLevitation_Template_B.posizione
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3;
	
	  ;% MagneticLevitation_Template_B.corrente
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 4;
	
	  ;% MagneticLevitation_Template_B.Saturation
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 5;
	
	  ;% MagneticLevitation_Template_B.Output
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 6;
	
	  ;% MagneticLevitation_Template_B.ManualSwitch2
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 7;
	
	  ;% MagneticLevitation_Template_B.ManualSwitch4
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 8;
	
	  ;% MagneticLevitation_Template_B.x1
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 9;
	
	  ;% MagneticLevitation_Template_B.x2
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 10;
	
	  ;% MagneticLevitation_Template_B.TransferFcn
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 11;
	
	  ;% MagneticLevitation_Template_B.Add
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 12;
	
	  ;% MagneticLevitation_Template_B.Gain
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 13;
	
	  ;% MagneticLevitation_Template_B.Sum
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 14;
	
	  ;% MagneticLevitation_Template_B.Sum1
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 15;
	
	  ;% MagneticLevitation_Template_B.TmpSignalConversionAtStateSpace
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 16;
	
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
    ;% Auto data (MagneticLevitation_Template_DW)
    ;%
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% MagneticLevitation_Template_DW.HILInitialize_AOVoltages
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% MagneticLevitation_Template_DW.BallPositionandCurrent_Buffer
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% MagneticLevitation_Template_DW.NextOutput
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% MagneticLevitation_Template_DW.ToHostFile_PointsWritten
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% MagneticLevitation_Template_DW.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% MagneticLevitation_Template_DW.BallPositionandCurrent_PWORK
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
	  ;% MagneticLevitation_Template_DW.Scope_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 6;
	  section.data(2).dtTransOffset = 1;
	
	  ;% MagneticLevitation_Template_DW.Scope1_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 7;
	  section.data(3).dtTransOffset = 2;
	
	  ;% MagneticLevitation_Template_DW.Scope2_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 8;
	  section.data(4).dtTransOffset = 3;
	
	  ;% MagneticLevitation_Template_DW.Scope3_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 9;
	  section.data(5).dtTransOffset = 5;
	
	  ;% MagneticLevitation_Template_DW.Scope4_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 10;
	  section.data(6).dtTransOffset = 6;
	
	  ;% MagneticLevitation_Template_DW.Scope5_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 11;
	  section.data(7).dtTransOffset = 8;
	
	  ;% MagneticLevitation_Template_DW.Scope6_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 12;
	  section.data(8).dtTransOffset = 10;
	
	  ;% MagneticLevitation_Template_DW.ToHostFile_PWORK
	  section.data(9).logicalSrcIdx = 13;
	  section.data(9).dtTransOffset = 12;
	
	  ;% MagneticLevitation_Template_DW.Voltage_PWORK
	  section.data(10).logicalSrcIdx = 14;
	  section.data(10).dtTransOffset = 14;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% MagneticLevitation_Template_DW.RandSeed
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
	  ;% MagneticLevitation_Template_DW.ToHostFile_SamplesCount
	  section.data(2).logicalSrcIdx = 16;
	  section.data(2).dtTransOffset = 1;
	
	  ;% MagneticLevitation_Template_DW.ToHostFile_ArrayNameLength
	  section.data(3).logicalSrcIdx = 17;
	  section.data(3).dtTransOffset = 2;
	
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


  targMap.checksum0 = 2502346040;
  targMap.checksum1 = 1448473795;
  targMap.checksum2 = 1011222565;
  targMap.checksum3 = 1854269446;

