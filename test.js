const assert = require('assert')

assert.deepEqual(process.env.TEST, 'test')

require('./')()

assert.notEqual(process.env.TEST, 'test')
