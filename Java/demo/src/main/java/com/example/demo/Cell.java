package com.example.demo;

import javafx.scene.control.Button;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;

import java.awt.*;

public class Cell extends Button {
    int x, y, value;
    private boolean marked = false, opened = false;
    public boolean isMarked(){
        return marked;
    }
    Cell(int x, int y, int value){
        this.x = x;
        this.y = y;
        this.value = value;
        this.setPrefSize(50,50);



    }
    public int getValue(){
        /*if (this.value == -1)
            FileInputStream input = new FileInputStream("resources/images/iconmonstr-home-6-48.png");
            Image imageMina = new Image(input);
            ImageView imageView = new ImageView(imageMina);
            return imageMina;*/
        return  this.value;
    }
    public void setValue(int value){
        this.value = value;
    }
    public boolean isBomb(){
        return this.value == -1;
    }
    public void open(){

        if(this.getValue() != -1)
            this.setText(Integer.toString(this.getValue()));

        else {
            Image imageMina = new Image("mina.jpg", 15, 15, true, true);
            this.graphicProperty().setValue(new ImageView(imageMina));
        }
        this.setDisable(true);
        this.opened = true;

    }
    public boolean isOpened(){
        return opened;
    }

    public void markAsBomb(){
        if(!marked){
            Image imageFlag = new Image("flag.png", 15, 15, true, true);
            this.graphicProperty().setValue(new ImageView(imageFlag));

        }
        else{
            this.graphicProperty().setValue(null);
        }
        marked = !marked;
    }

    public void setColor(Color white) {
    }
}
