#include "ofSoundStream.h"
#include "ofAppRunner.h"

ofSoundStream soundStreamInput;
ofSoundStream soundStreamOutput;	

//------------------------------------------------------------
void ofSoundStreamSetup(int nOutputChannels, int nInputChannels, ofBaseApp * appPtr){
	if( appPtr == NULL ){
		appPtr = ofGetAppPtr();
	}
	ofSoundStreamSetup(nOutputChannels, nInputChannels, appPtr, 44100, 256, 4);
}

//------------------------------------------------------------
void ofSoundStreamSetup(int nOutputChannels, int nInputChannels, int sampleRate, int bufferSize, int nBuffers){
	ofSoundStreamSetup(nOutputChannels, nInputChannels, ofGetAppPtr(), sampleRate, bufferSize, nBuffers);
}

//------------------------------------------------------------
void ofSoundStreamSetup(int nOutputChannels, int nInputChannels, ofBaseApp * appPtr, int sampleRate, int bufferSize, int nBuffers){
	soundStreamOutput.setup(appPtr, nOutputChannels, nInputChannels, sampleRate, bufferSize, nBuffers);
}

//------------------------------------------------------------
void ofSoundStreamStop(){
	soundStreamOutput.stop();
	soundStreamInput.stop();
}

//------------------------------------------------------------
void ofSoundStreamStart(){
	soundStreamOutput.start();
	soundStreamInput.start();
}

//------------------------------------------------------------
void ofSoundStreamClose(){
	soundStreamOutput.close();
	soundStreamInput.close();
}

//------------------------------------------------------------
void ofSoundStreamListDevices(){
	soundStreamOutput.listDevices();
}

//------------------------------------------------------------
ofSoundStream::ofSoundStream(){
	setSoundStream( ofPtr<OF_SOUND_STREAM_TYPE>(new OF_SOUND_STREAM_TYPE) );
}

//------------------------------------------------------------
void ofSoundStream::setSoundStream(ofPtr<ofBaseSoundStream> soundStreamPtr){
	soundStream = soundStreamPtr;
}

//------------------------------------------------------------
ofPtr<ofBaseSoundStream> ofSoundStream::getSoundStream(){
	return soundStream;
}

//------------------------------------------------------------
void ofSoundStream::listDevices(){
	if( soundStream ){
		soundStream->listDevices();
	}
}

//------------------------------------------------------------
void ofSoundStream::setDeviceID(int deviceID){
	if( soundStream ){
		soundStream->setDeviceID(deviceID);
	}	
}

//------------------------------------------------------------
bool ofSoundStream::setup(ofBaseApp * app, int outChannels, int inChannels, int sampleRate, int bufferSize, int nBuffers){
	if( soundStream ){
		soundStream->setup(app, outChannels, inChannels, sampleRate, bufferSize, nBuffers);
		return true;
	}
	return false;
}

//------------------------------------------------------------
void ofSoundStream::setInput(ofBaseSoundInput * soundInput){
	if( soundStream ){
		soundStream->setInput(soundInput);
	}
}

//------------------------------------------------------------
void ofSoundStream::setOutput(ofBaseSoundOutput * soundOutput){
	if( soundStream ){
		soundStream->setOutput(soundOutput);
	}
}

//------------------------------------------------------------
bool ofSoundStream::setup(int outChannels, int inChannels, int sampleRate, int bufferSize, int nBuffers){
	if( soundStream ){
		soundStream->setup(outChannels, inChannels, sampleRate, bufferSize, nBuffers);
		return true;
	}
	return false;
}

//------------------------------------------------------------
void ofSoundStream::start(){
	if( soundStream ){
		soundStream->start();
	}
}

//------------------------------------------------------------
void ofSoundStream::stop(){
	if( soundStream ){
		soundStream->stop();
	}
}

//------------------------------------------------------------
void ofSoundStream::close(){
	if( soundStream ){
		soundStream->close();
	}
}

//------------------------------------------------------------
long unsigned long ofSoundStream::getTickCount(){
	if( soundStream ){
		return soundStream->getTickCount();
	}
	return 0;
}

