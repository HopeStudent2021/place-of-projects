package com.example.demo;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.ButtonType;
import java.util.Optional;

public class Map {
    Cell[][] map;
    public Cell[][] getCells(){
        return map;
    }
    Map(int m, int n, int bombsCount){
        newMap(m,n, bombsCount);

    }


    public void gameOver(){
        final int m = map.length;
        final int n = map[0].length;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                map[i][j].open();
            }
        }

    }
    public boolean dialog() {

        Alert alert = new Alert(Alert.AlertType.ERROR);
        alert.setTitle("Game Over");
        alert.setHeaderText("Результат");
        alert.setContentText("Наткнулись на бомбу");

        ButtonType btnRestart = new ButtonType("Рестарт");
        alert.getButtonTypes().setAll(btnRestart);

        Optional<ButtonType> result = alert.showAndWait();
        Button restart = (Button) alert.getDialogPane().lookupButton(ButtonType.YES);
        restart.setDefaultButton(true);

        /*restart.setOnAction(new EventHandler<ActionEvent>() {

            @Override
            public void handle(ActionEvent event) {
                restart(getM(), getN());
            }
        });*/

            return result.get() == ButtonType.OK;

        //oke button is pressed

        //return result.get() == (ButtonType.YES);

    }
    public int getM(){
        return map.length;
    }
    public int getN(){
        return map[0].length;
    }

    private void newMap(int m, int n, int bombsCount) {
        double probability = (double) bombsCount / (m * n);
        this.map = new Cell[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                map[i][j] = new Cell(i, j, 0);
            }
        }
        int currentCount = 0, randomX = 0, randomY = 0;
        while (currentCount < bombsCount) {
            randomX = (int)(Math.random() * m);
            randomY = (int)(Math.random() * n);
            if(!map[randomX][randomY].isBomb()) {
                map[randomX][randomY] = new Cell(randomX, randomY, -1);
                currentCount++;

            }

        }

        //Image imageMina = new Image("mina.png");
        for(int i = 0; i< m; i++) {
            for (int j = 0; j < n; j++) {
                map[i][j].setValue(calculateMinsAround(map,i,j));
            }
        }
    }
    public void openAround(int x, int y){
        int m = map.length;
        int n = map[0].length;

        int leftX = x == 0 ? 0 : x - 1;
        int rightX = x + 1 >= m ? x : x + 1;
        int topY = y == 0 ? 0 : y - 1;
        int bottomY = y + 1 >= n ? y : y + 1;

        for (int l = leftX; l <= rightX; l++) {
            for (int o = topY; o <= bottomY; o++) {
                if(l == x && o == y)
                    continue;
                if(!map[l][o].isOpened()) {
                    map[l][o].open();

                    if(map[l][o].getValue() == 0)
                        openAround(l, o);
                }
            }
        }

    }
    public boolean isWin(){
        final int  m = map.length;
        final int n = map[0].length;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(!map[i][j].isOpened() && !map[i][j].isMarked()){
                    return false;
                }

            }
        }
        return true;
    }
    private int calculateMinsAround(Cell[][] map,int x, int y){

        int m = map.length;
        int n = map[0].length;
        if(map[x][y].isBomb())
            return  -1;
        else{
            int leftX = x == 0 ? 0 : x - 1;
            int rightX = x + 1 >= m ? x : x + 1;
            int topY = y == 0 ? 0 : y - 1;
            int bottomY = y + 1 >= n ? y : y + 1;
            int minesQty = 0;
            for (int l = leftX; l <= rightX; l++) {
                for (int o = topY; o <= bottomY; o++) {
                    if (!(l == x && o == y) && map[l][o].isBomb()) {
                        minesQty++;
                    }
                }
            }
           return minesQty;

        }
    }
}
