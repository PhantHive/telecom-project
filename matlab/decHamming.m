function decDt = decHamming(cdWrd,m,k)
% The function performs decoding of Hamming group (m,k) codewords specified in
% matrix form for multiple codewords.
% Input:
%   cdWrd - a matrix with m rows, each row represents a single codeword to be decoded;
%   m     - Hamming codeword length;
%   k     - number of information symbols per codeword;
% Output:
%   decDt - a matrix with k rows, each row represents a decoded and corrected information block.
  
% First, determine the number of control symbols  
r = m - k;

% ------- Group code only! -------------------------------------------------
% Find logical indices of data symbol positions 'idxC' and control symbol positions 'idxE'
i = 1:m;                          % All indices, from 1 to m: 1, 2, 3, 4, ..., m
idxE = rem(log2(i),1) < 1e-10;    % Control symbols are located at power of 2 positions only
                                  % Compare with very small value to convert to logical 1 and 0
idxC = ~idxE;

% ------- Systematic code only! Comment it otherwise -----------------------
%TMP = cdWrd;
%cdWrd(:,idxE) = TMP(:,end-r+1:end);
%cdWrd(:,idxC) = TMP(:,1:k);

% Specify syndrome calculation matrix
% Each column contains symbols from equations
SynMtx = ...
                [0 0 0 0 1; 
                0 0 0 1 0; 
                0 0 0 1 1; 
                0 0 1 0 0; 
                0 0 1 0 1; 
                0 0 1 1 0; 
                0 0 1 1 1; 
                0 1 0 0 0; 
                0 1 0 0 1; 
                0 1 0 1 0; 
                0 1 0 1 1; 
                0 1 1 0 0; 
                0 1 1 0 1; 
                0 1 1 1 0; 
                0 1 1 1 1; 
                1 0 0 0 0; 
                1 0 0 0 1; 
                1 0 0 1 0; 
                1 0 0 1 1; 
                1 0 1 0 0; 
                1 0 1 0 1; 
                1 0 1 1 0; 
                1 0 1 1 1; 
                1 1 0 0 0; 
                1 1 0 0 1; 
                1 1 0 1 0; 
                1 1 0 1 1];

% Calculate syndrome for each codeword
% Use rem() function to find modulo 2 sum as a remainder of division by 2
SynVal = rem(cdWrd * SynMtx, 2);     % Use matrix multiplication to improve performance
SynVal = SynVal * 2.^(r-1:-1:0)';

idxErr = SynVal .* (SynVal <= m);    % Error indices match symbol positions for Group code


% Specify table of all error vector. Note: the first row must be "no errors" vector.
ErrVec = ...
[zeros(1,m)
 eye(m)]; 

% Perform correction, by adding error vector to received codeword.
% Note: Add +1 to syndrom because of indexing in Matlab (starts from 1, not 0)
CorWrd = rem(cdWrd + ErrVec(idxErr+1,:),2);

% Read the columns of data symbols to form decoded data
decDt = CorWrd(:,idxC);   % Group code