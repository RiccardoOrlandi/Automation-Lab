function add_data(percorso)
% add_data - questa funzione aggiunge tutti i file .mat presenti in una
%            cartella salvandoli con il loro nome (non con la data) 
%            nel workspace
%
% Syntax
% add_data(percorso)
%
% Input Argument
% percorso - deve essere una stringa, indica il percorso relativo dove trovare
%            le misure da inserire (esempio: '\data\Step Test'

% parametri sensori
offset_corrente = 0.016;
offset_posizione = 0.0236;
k_b = 2.686e-3;



folder = pwd;   % pwd serve per recuperare il percorso corrente della cartella matlab
folder = fullfile(folder, percorso);

% Ottieni una lista di tutti i file .mat nella cartella
files = dir(fullfile(folder, '*.mat'));

% Carica ogni file .mat nel workspace
for k = 1:length(files)
    % Costruisci il percorso completo del file
    filePath = fullfile(folder, files(k).name);
    
    % Carica il file .mat nel workspace
    data = load(filePath);
    campi = fieldnames(data);
    nome = campi{1};  % Nome della variabile che vuoi rinominare
    prova = files(k).name;
    prova = strrep(prova(1:end-4), ',', '_');
    segnale = data.(nome);
    posizione = (segnale(2,:)+offset_posizione)*k_b;
    corrente = segnale(3,:)+offset_corrente;
    segnale = [segnale(1, :); posizione; corrente];
    
    %assignin('base', prova,  data.(nome));
    assignin('base', prova,  segnale);
    
    
    % (Facoltativo) Visualizza il nome del file caricato
    
    % disp(['Caricato: ', files(k).name]);
end