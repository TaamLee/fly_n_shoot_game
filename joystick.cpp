#include "joystick.h"
#include <QFile>
#include <fcntl.h>
#include <unistd.h>
#include <QDebug>

void Joystick::run() {

    int fd = open("/dev/input/js0", O_RDONLY | O_NONBLOCK);
    if (fd < 0) {
        qDebug() << "Failed to open joystick";
        return;
    }
    qDebug() << "open file successfull";
    struct js_event js;
    while (!stopThread) {
        ssize_t bytes = read(fd, &js, sizeof(struct js_event));
        if ((bytes > 0) && js.value != 0) {
            emit joystickEvent(js.type, js.number,js.value);
        }
        msleep(1); // Sleep for a short time to prevent CPU overuse
    }

    close(fd);
}
void Joystick::stop() {
    stopThread = true;
}
