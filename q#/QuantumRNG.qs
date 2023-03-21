namespace QuantumRNG {

    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Convert;
    
    operation GenerateRandomBit() : Result {
        //allocate a qubit
        use q = Qubit();

        //put qubit into superposition
        H(q);

        //measure qubit value
        return M(q);
    }

    operation RandomNumberInRange(min: Int, max: Int) : Int{
        mutable output = 0;
        repeat{
            mutable bits = [];
            for idxBit in 1..BitSizeI(max){
                set bits += [GenerateRandomBit()];
            }
            set output = ResultArrayAsInt(bits);
        }until (output < max and output >=min);
        return output;
    }

    @EntryPoint()
    operation SampleRandomNumber() : Int{
        let min = 10;
        let max = 50;

        Message($"Sampling a random number between {min} and {max}: ");
        return RandomNumberInRange(min,max);
    }
}
