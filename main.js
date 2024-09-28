const { SerialPort } = require('serialport');
const { ReadlineParser } = require('@serialport/parser-readline');

const port = new SerialPort({ path: '/dev/ttyACM0', baudRate: 9600 });

const parser = port.pipe(new ReadlineParser({ delimiter: '\n' }));

// membaca pesan dari arduino
parser.on('data', (data) => {
    console.log('Data dari Arduino: ', data);
});

// Kirim pesan ke arduino
function sendMessageToArduino(message) {
    console.log(`Mengirim pesan ke Arduino: ${message}`);
    port.write(message + '\n', (err) => {
        if (err) {
            return console.log('Error saat mengirim pesan: ', err.message);
        }
        console.log('Pesan terkirim');
    });
}

setTimeout(() => {
    sendMessageToArduino("Hello Arduino!");
}, 2000);

port.on('error', (err) => {
    console.error('Error: ', err.message);
});
