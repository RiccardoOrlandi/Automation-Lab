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
    ;% Auto data (feedback_2019_P)
    ;%
      section.nData     = 18;
      section.data(18)  = dumData; %prealloc
      
	  ;% feedback_2019_P.A_ob
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% feedback_2019_P.B_ob
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 9;
	
	  ;% feedback_2019_P.C_ob
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 18;
	
	  ;% feedback_2019_P.Kb
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 27;
	
	  ;% feedback_2019_P.offset_corrente_volt
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 28;
	
	  ;% feedback_2019_P.offset_posizione_volt
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 29;
	
	  ;% feedback_2019_P.u
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 30;
	
	  ;% feedback_2019_P.x1_eq0
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 31;
	
	  ;% feedback_2019_P.x2_eq0
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 32;
	
	  ;% feedback_2019_P.PIDController_D
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 33;
	
	  ;% feedback_2019_P.PIDController_I
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 34;
	
	  ;% feedback_2019_P.PIDController_InitialConditionF
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 35;
	
	  ;% feedback_2019_P.PIDController_InitialConditio_i
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 36;
	
	  ;% feedback_2019_P.PIDController_N
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 37;
	
	  ;% feedback_2019_P.PIDController_P
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 38;
	
	  ;% feedback_2019_P.Subsystem1_p1
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 39;
	
	  ;% feedback_2019_P.Subsystem1_p2
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 40;
	
	  ;% feedback_2019_P.Subsystem1_p3
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 41;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% feedback_2019_P.BallPositionandCurrent_channels
	  section.data(1).logicalSrcIdx = 18;
	  section.data(1).dtTransOffset = 0;
	
	  ;% feedback_2019_P.Voltage_channels
	  section.data(2).logicalSrcIdx = 19;
	  section.data(2).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 25;
      section.data(25)  = dumData; %prealloc
      
	  ;% feedback_2019_P.HILInitialize_OOTerminate
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
	  ;% feedback_2019_P.HILInitialize_OOExit
	  section.data(2).logicalSrcIdx = 21;
	  section.data(2).dtTransOffset = 1;
	
	  ;% feedback_2019_P.HILInitialize_AOFinal
	  section.data(3).logicalSrcIdx = 22;
	  section.data(3).dtTransOffset = 2;
	
	  ;% feedback_2019_P.HILInitialize_POFinal
	  section.data(4).logicalSrcIdx = 23;
	  section.data(4).dtTransOffset = 3;
	
	  ;% feedback_2019_P.Step_Time
	  section.data(5).logicalSrcIdx = 24;
	  section.data(5).dtTransOffset = 4;
	
	  ;% feedback_2019_P.Step_Y0
	  section.data(6).logicalSrcIdx = 25;
	  section.data(6).dtTransOffset = 5;
	
	  ;% feedback_2019_P.Step_YFinal
	  section.data(7).logicalSrcIdx = 26;
	  section.data(7).dtTransOffset = 6;
	
	  ;% feedback_2019_P.TransferFcn_A
	  section.data(8).logicalSrcIdx = 27;
	  section.data(8).dtTransOffset = 7;
	
	  ;% feedback_2019_P.TransferFcn_C
	  section.data(9).logicalSrcIdx = 28;
	  section.data(9).dtTransOffset = 8;
	
	  ;% feedback_2019_P.TransferFcn1_A
	  section.data(10).logicalSrcIdx = 29;
	  section.data(10).dtTransOffset = 9;
	
	  ;% feedback_2019_P.TransferFcn1_C
	  section.data(11).logicalSrcIdx = 30;
	  section.data(11).dtTransOffset = 10;
	
	  ;% feedback_2019_P.Stateobserver_InitialCondition
	  section.data(12).logicalSrcIdx = 31;
	  section.data(12).dtTransOffset = 11;
	
	  ;% feedback_2019_P.TransferFcn_A_f
	  section.data(13).logicalSrcIdx = 32;
	  section.data(13).dtTransOffset = 14;
	
	  ;% feedback_2019_P.TransferFcn_C_j
	  section.data(14).logicalSrcIdx = 33;
	  section.data(14).dtTransOffset = 15;
	
	  ;% feedback_2019_P.TransferFcn_D
	  section.data(15).logicalSrcIdx = 34;
	  section.data(15).dtTransOffset = 16;
	
	  ;% feedback_2019_P.TransferFcn1_A_c
	  section.data(16).logicalSrcIdx = 35;
	  section.data(16).dtTransOffset = 17;
	
	  ;% feedback_2019_P.TransferFcn1_C_a
	  section.data(17).logicalSrcIdx = 36;
	  section.data(17).dtTransOffset = 18;
	
	  ;% feedback_2019_P.TransferFcn1_D
	  section.data(18).logicalSrcIdx = 37;
	  section.data(18).dtTransOffset = 19;
	
	  ;% feedback_2019_P.TransferFcn2_A
	  section.data(19).logicalSrcIdx = 38;
	  section.data(19).dtTransOffset = 20;
	
	  ;% feedback_2019_P.TransferFcn2_C
	  section.data(20).logicalSrcIdx = 39;
	  section.data(20).dtTransOffset = 21;
	
	  ;% feedback_2019_P.TransferFcn2_D
	  section.data(21).logicalSrcIdx = 40;
	  section.data(21).dtTransOffset = 22;
	
	  ;% feedback_2019_P.Constant_Value
	  section.data(22).logicalSrcIdx = 41;
	  section.data(22).dtTransOffset = 23;
	
	  ;% feedback_2019_P.Saturation_UpperSat
	  section.data(23).logicalSrcIdx = 42;
	  section.data(23).dtTransOffset = 29;
	
	  ;% feedback_2019_P.Saturation_LowerSat
	  section.data(24).logicalSrcIdx = 43;
	  section.data(24).dtTransOffset = 30;
	
	  ;% feedback_2019_P.Gain_Gain
	  section.data(25).logicalSrcIdx = 44;
	  section.data(25).dtTransOffset = 31;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% feedback_2019_P.ToHostFile_Decimation
	  section.data(1).logicalSrcIdx = 45;
	  section.data(1).dtTransOffset = 0;
	
	  ;% feedback_2019_P.ToHostFile_BitRate
	  section.data(2).logicalSrcIdx = 46;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% feedback_2019_P.HILInitialize_Active
	  section.data(1).logicalSrcIdx = 47;
	  section.data(1).dtTransOffset = 0;
	
	  ;% feedback_2019_P.HILInitialize_AOTerminate
	  section.data(2).logicalSrcIdx = 48;
	  section.data(2).dtTransOffset = 1;
	
	  ;% feedback_2019_P.HILInitialize_AOExit
	  section.data(3).logicalSrcIdx = 49;
	  section.data(3).dtTransOffset = 2;
	
	  ;% feedback_2019_P.HILInitialize_DOTerminate
	  section.data(4).logicalSrcIdx = 50;
	  section.data(4).dtTransOffset = 3;
	
	  ;% feedback_2019_P.HILInitialize_DOExit
	  section.data(5).logicalSrcIdx = 51;
	  section.data(5).dtTransOffset = 4;
	
	  ;% feedback_2019_P.HILInitialize_POTerminate
	  section.data(6).logicalSrcIdx = 52;
	  section.data(6).dtTransOffset = 5;
	
	  ;% feedback_2019_P.HILInitialize_POExit
	  section.data(7).logicalSrcIdx = 53;
	  section.data(7).dtTransOffset = 6;
	
	  ;% feedback_2019_P.HILInitialize_DOFinal
	  section.data(8).logicalSrcIdx = 54;
	  section.data(8).dtTransOffset = 7;
	
	  ;% feedback_2019_P.BallPositionandCurrent_Active
	  section.data(9).logicalSrcIdx = 55;
	  section.data(9).dtTransOffset = 8;
	
	  ;% feedback_2019_P.Voltage_Active
	  section.data(10).logicalSrcIdx = 56;
	  section.data(10).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% feedback_2019_P.ManualSwitch1_CurrentSetting
	  section.data(1).logicalSrcIdx = 57;
	  section.data(1).dtTransOffset = 0;
	
	  ;% feedback_2019_P.ManualSwitch2_CurrentSetting
	  section.data(2).logicalSrcIdx = 58;
	  section.data(2).dtTransOffset = 1;
	
	  ;% feedback_2019_P.ToHostFile_file_name
	  section.data(3).logicalSrcIdx = 59;
	  section.data(3).dtTransOffset = 2;
	
	  ;% feedback_2019_P.ToHostFile_VarName
	  section.data(4).logicalSrcIdx = 60;
	  section.data(4).dtTransOffset = 32;
	
	  ;% feedback_2019_P.ToHostFile_FileFormat
	  section.data(5).logicalSrcIdx = 61;
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
    ;% Auto data (feedback_2019_B)
    ;%
      section.nData     = 13;
      section.data(13)  = dumData; %prealloc
      
	  ;% feedback_2019_B.Step
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% feedback_2019_B.posizione
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% feedback_2019_B.corrente
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% feedback_2019_B.FilterCoefficient
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% feedback_2019_B.TransferFcn
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% feedback_2019_B.TransferFcn1
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% feedback_2019_B.TransferFcn2
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% feedback_2019_B.Saturation
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% feedback_2019_B.TmpSignalConversionAtStateobser
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% feedback_2019_B.Gain
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 11;
	
	  ;% feedback_2019_B.IntegralGain
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 12;
	
	  ;% feedback_2019_B.K
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 13;
	
	  ;% feedback_2019_B.beta
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 16;
	
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
    ;% Auto data (feedback_2019_DW)
    ;%
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% feedback_2019_DW.HILInitialize_AOVoltages
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% feedback_2019_DW.BallPositionandCurrent_Buffer
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% feedback_2019_DW.ToHostFile_PointsWritten
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% feedback_2019_DW.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% feedback_2019_DW.BallPositionandCurrent_PWORK
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% feedback_2019_DW.Scope_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
	  ;% feedback_2019_DW.Scope1_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 3;
	
	  ;% feedback_2019_DW.Scope2_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 7;
	  section.data(4).dtTransOffset = 4;
	
	  ;% feedback_2019_DW.ToHostFile_PWORK
	  section.data(5).logicalSrcIdx = 8;
	  section.data(5).dtTransOffset = 5;
	
	  ;% feedback_2019_DW.Voltage_PWORK
	  section.data(6).logicalSrcIdx = 9;
	  section.data(6).dtTransOffset = 7;
	
	  ;% feedback_2019_DW.Scope_PWORK_d.LoggedData
	  section.data(7).logicalSrcIdx = 10;
	  section.data(7).dtTransOffset = 8;
	
	  ;% feedback_2019_DW.Scope1_PWORK_n.LoggedData
	  section.data(8).logicalSrcIdx = 11;
	  section.data(8).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% feedback_2019_DW.ToHostFile_SamplesCount
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
	  ;% feedback_2019_DW.ToHostFile_ArrayNameLength
	  section.data(2).logicalSrcIdx = 13;
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


  targMap.checksum0 = 1335590053;
  targMap.checksum1 = 1369214997;
  targMap.checksum2 = 254063470;
  targMap.checksum3 = 2600211770;

