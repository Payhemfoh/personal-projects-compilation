public class Week10_Lab2 {
    private String artist;
    private String title;
    private int cost;

    public Week10_Lab2(){
        this("","",0);
    }

    public Week10_Lab2(String artist,String title,int cost){
        this.artist = artist;
        this.title = title;
        this.cost = cost;
    }

    public String getArtist(){return this.artist;}
    public String getTitle(){return this.title;}
    public int getCost(){return this.cost;}

    public void setArtist(String artist) {this.artist = artist; }
    public void setCost(int cost) { this.cost = cost; }
    public void setTitle(String title) { this.title = title; }

    public String toString(){return "Artist:"+artist+"\nTitle:"+title+"\nCost:"+cost;}
}
