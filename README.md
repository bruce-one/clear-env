# Clear env

Simple module to clear /proc/pid/environ. Also clears process.env.

## Example

    TEST=test node
    > console.log(process.env.TEST) // test
    > /[a-zA-Z0-9]/.test(fs.readFileSync(`/proc/${process.pid}/environ`, 'utf8')) // true
    > require('clear-env')()
    > console.log(process.env.TEST) // undefined
    > console.log(process.env) // {}
    > /[a-zA-Z0-9]/.test(fs.readFileSync(`/proc/${process.pid}/environ`, 'utf8')) // false
