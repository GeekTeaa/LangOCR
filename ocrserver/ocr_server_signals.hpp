#ifndef _OCRSERVER_OCR_SERVER_SIGNALS_
#define _OCRSERVER_OCR_SERVER_SIGNALS_

namespace signals {

    typedef void (*SignalHandlerFunction)(int);
    
    struct Signal {
        int sig;
        SignalHandlerFunction func; 
    }; 
    
    class SignalInitializer {
    public:
        SignalInitializer(void)  { return; }
        ~SignalInitializer(void) { return; }

        void SetUpSignalHandling(void);
    };
    
    

}

#endif 
