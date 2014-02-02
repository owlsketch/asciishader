#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    stipFont.loadFont("verdana.ttf",5,true);
    medFont.loadFont("verdana.ttf",10,true);

    photo.loadImage("mod.jpg");
    photo.setAnchorPercent(.5,.5); //sets anchor at center, 50% in range of 0.0 - 1.0
    photo.setImageType(OF_IMAGE_GRAYSCALE);


    ofSetWindowShape(photo.getWidth(),photo.getHeight());
    ofSetWindowTitle("AlphaLetra");

    ofBackgroundHex(0xD9DEDA);

    blk = ofColor::black;

    unsigned char * pixels = photo.getPixels();

    pos1 = true;
    dubs = false;
    noir = false;

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

    ofSetColor(blk);

    photo.draw(ofGetWindowWidth()/2,ofGetWindowHeight()/2);
    if(noir == true)
    {
        ofBackground(ofColor::white);
    }
    if(dubs == false)
    {
    photo.loadImage("mod.jpg");
    photo.setImageType(OF_IMAGE_GRAYSCALE);

    for(int i = 0; i < photo.width; i+=4)
    {
        int j = 0;
        while(j < photo.height)
        {
            if(pos1){
            holder = photo.getColor(i,j);
                if(holder.getBrightness() < 40)
                {
                photo.setColor(i,j,blk);
                stipFont.drawString("O",i,j);
                j+=2;
                }
                else if(holder.getBrightness() < 80 && holder.getBrightness() >= 40)
                {
                    photo.setColor(i,j,blk);
                    stipFont.drawString("O",i,j);
                    j+= 3;
                }
                else if (holder.getBrightness() < 120 && holder.getBrightness() >= 80)
                    {
                    photo.setColor(i,j,blk);
                    medFont.drawString("o",i,j);
                    j += 4;
                }
                else if (holder.getBrightness() < 160 && holder.getBrightness() >= 120)
                {
                    photo.setColor(i,j,blk);
                    medFont.drawString(".",i,j);
                    j += 5;
                }
                else if (holder.getBrightness() < 220 && holder.getBrightness() >= 160)
                {
                    photo.setColor(i,j,blk);
                    stipFont.drawString(".",i,j);
                    j += 6;
                }
                else
                {
                    photo.setColor(i,j,blk);
                    stipFont.drawString(".",i,j);
                    j += 7;
                }
            }
            else{photo.setColor(i,j, ofColor::black);} //if uploading second part

        }

    }
    }
    if(dubs == true)
    {
    for (int i =1; i <photo.width; i+=2)
    {
        for(int j = 1; j < photo.height; j+=2)
        {
            if(pos1) {
                photo.setColor(i,j, ofColor(105,105,105));
            }
            else{photo.setColor(i,j, ofColor(0,0,0));}
        }
    }
    }

    photo.update();


}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    cout << key << endl;
    if (key == 32) //spacebar
    {
        if (pos1){
            pos1 = false;
        }
        else {
            pos1 = true;
        }
    }
    if(key == 100) //D
    {
        if(dubs){dubs=false;}
        else{dubs=true;}
    }
    if(key == 110)
    {
        if(noir){noir =false;}
        else{noir = true;}
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}
