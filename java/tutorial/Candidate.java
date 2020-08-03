public class Candidate {
    private String name;
    private int vote;

    public Candidate(String name){
        this.name = name;
        this.vote = 0;
    }

    public String getName(){return this.name;}
    public int getVote(){return this.vote;}
    public void setName(String name){this.name = name;}
    public void incrementVoteCount(){++this.vote;}
    @Override
    public boolean equals(Object o){
        return true;
    }
}

class VotingMachine{
    private Candidate candidateList[];
    private int count;

    public VotingMachine(int size){
        this.candidateList = new Candidate[size];
        for(int i=0;i<this.candidateList.length;++i) {
            this.candidateList[i] = new Candidate("");
        }
        this.count=0;
    }

    public void addCandidate(String name){
        boolean isValid = true;
        if(name==null)
            isValid = false;

        if(this.count == this.candidateList.length)
            isValid = false;

        if(isValid){
            for(int i=0;i<count;++i){
                if(name.equals(this.candidateList[i].getName()) )
                    isValid = false;
            }
        }

        if(isValid){
            this.candidateList[count].setName(name);
            ++this.count;
        }
    }

    public void castVote(String name){
        for(int i=0;i<count;++i){
            if(name.equals(this.candidateList[i].getName())){
                this.candidateList[i].incrementVoteCount();
            }
        }
    }

    public void printResults(){
        for(int i=0;i<count;++i)
        System.out.printf("%-30s has received %-8d votes \n",
                        this.candidateList[i].getName(),
                        this.candidateList[i].getVote()
                        );
    }
}

class TestVotingMachine{
    public static void main(String[] args){
        final int SIZE = 3;
        final String NAMELIST[] = {"Joe", "Kelvin", "Mr Lai"};
        VotingMachine v = new VotingMachine(SIZE);
        for(int i=0;i<SIZE;++i){
            v.addCandidate(NAMELIST[i]);
        }
        v.castVote("Joe");
        v.printResults();

    }
}


