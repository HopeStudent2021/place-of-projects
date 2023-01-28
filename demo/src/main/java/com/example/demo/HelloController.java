package com.example.demo;

import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.input.MouseButton;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.Background;
import javafx.scene.layout.GridPane;
import javafx.scene.paint.Color;

public class HelloController {
    @FXML
    private Label counter;

    @FXML
    private GridPane grid;


    @FXML
    private Button button;
    @FXML
    protected void restart() {
        reset();
        button.setText("Restart");

        makeGrid(5,5, 10);
    }
    private void reset(){
        int len = this.grid.getChildren().size();
        for (int i = len-1; i >= 0; i--){
            this.grid.getChildren().remove(i);
        }
    }
    private void makeGrid(int x, int y, int bombsCount){

        Map map = new Map(x,y, bombsCount);
        Cell[][] cells = map.getCells();
        for(int i = 0; i < x; i++){
            for(int j = 0; j < y; j++){
                Cell cell = cells[i][j];


                cell.setStyle("-fx-font-size: 2em; ");
                cell.addEventHandler(MouseEvent.MOUSE_CLICKED, new EventHandler<MouseEvent>() {
                    @Override
                    public void handle(MouseEvent e) {
                        if(e.getButton() == MouseButton.PRIMARY){
                            if(cell.getValue() == 0){
                                cell.setBackground(Background.fill(Color.YELLOW));
                            }
                            else if (cell.getValue() == 1) {
                                cell.setBackground(Background.fill(Color.YELLOWGREEN));
                            }
                            else if(cell.getValue()>= 2){
                                cell.setBackground(Background.fill(Color.PINK));
                            }
                            else if(cell.getValue()>= 3){
                                cell.setBackground(Background.fill(Color.BLUE));
                            }
                            else if(cell.getValue()>= 4){
                                cell.setBackground(Background.fill(Color.PEACHPUFF));
                            }
                            else if(cell.getValue()>= 5){
                                cell.setBackground(Background.fill(Color.ORANGE));
                            }


                            if(cell.isMarked()){
                                return;}
                            if(cell.getValue() == 0)
                                map.openAround(cell.x,cell.y);

                            cell.open();


                            //cell.setStyle("-fx-font-size:18");
                            cell.setStyle("-fx-font-size: 2em; ");


                            if(cell.isBomb()){
                                button.setText("You Lose!!!");
                                cell.setBackground(Background.fill(Color.RED));
                                if(cell.getValue() == 0){
                                    cell.setBackground(Background.fill(Color.YELLOW));
                                }
                                else if (cell.getValue() == 1) {
                                    cell.setBackground(Background.fill(Color.YELLOWGREEN));
                                }
                                else if(cell.getValue()>= 2){
                                    cell.setBackground(Background.fill(Color.PINK));
                                }
                                else if(cell.getValue()>= 3){
                                    cell.setBackground(Background.fill(Color.BLUE));
                                }
                                else if(cell.getValue()>= 4){
                                    cell.setBackground(Background.fill(Color.PEACHPUFF));
                                }
                                else if(cell.getValue()>= 5){
                                    cell.setBackground(Background.fill(Color.ORANGE));
                                }
                                map.gameOver();
                                return;
                            }

                            if(map.isWin())
                                button.setText("You Win!!!");

                        }

                    }
                });
                cell.addEventHandler(MouseEvent.MOUSE_CLICKED, new EventHandler<MouseEvent>() {

                    @Override
                    public void handle(MouseEvent t) {
                        if(t.getButton() == MouseButton.SECONDARY) {
                            cell.markAsBomb();
                            if(map.isWin())
                                button.setText("You Win!!!");
                        }
                    }
                });

                grid.add(cell, i*20,j+20);
            }
        }
    }
}

