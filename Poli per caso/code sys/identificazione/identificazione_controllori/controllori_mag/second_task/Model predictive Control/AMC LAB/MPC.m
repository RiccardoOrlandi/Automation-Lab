classdef MPC < matlab.System
    % MPC Model Predictive Control Block
   
    % Public, tunable properties
    properties(Nontunable)
        % N Prediction Horizon
        N = 20;
        % Q Matrix
        Q = eye(3);
        % R Matrix
        R = 0;
        % tau_s Sampling Time
        tau_s = 1;
    end

    methods(Access = protected)
        function u_opt = stepImpl(obj, xk, h1_ref)
            tic
            % Given y_ref, compute (x_bar, u_bar)
            [ x_bar, u_bar ] = compute_equilibrium(h1_ref); 
            
            % Solve the FHCOP
            u_opt = FHOCP(xk, obj.Q, obj.R, obj.N, x_bar, u_bar, obj.tau_s);
            time_elapsed = toc;
            assignin('base', 'time_elapsed',time_elapsed)
        end


        function num = getNumInputsImpl(~)
            % Define total number of inputs for system with optional inputs
            num = 2;
        end


        function num = getNumOutputsImpl(~)
            % Define total number of outputs for system with optional
            % outputs
            num = 1;
        end


        function out = getOutputSizeImpl(~)
            % Return size for each output port
            out = [1 1]; % a scalar
        end


        function out = getOutputDataTypeImpl(~)
            % Return data type for each output port
            out = "double";
        end


        function out = isOutputComplexImpl(~)
            % Return true for each output port with complex data
            out = false;
        end


        function out = isOutputFixedSizeImpl(~)
            % Return true for each output port with fixed size
            out = true;
        end


        function sts = getSampleTimeImpl(obj)
            % Define sample time type and parameters
            sts = obj.createSampleTime("Type", "Discrete", "SampleTime", obj.tau_s);
        end


    end
end
