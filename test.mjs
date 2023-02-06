const obj = await (await import('./a.out.js')).default()
const a = new obj.A()
const field = a.field
field.num = 1
a.field.num = 2
console.log(field.num, a.field.num)
a.delete()
const a2 = new obj.A()
const field2 = a2.field
const field3 = field2.clone()
field2.num = 3
console.log(field.num)
console.log(field2.num)
console.log(field3.num)

console.log('emval_handles', obj.count_emval_handles())
console.log('getLiveInheritedInstances', obj.getLiveInheritedInstances())
console.log('getInheritedInstanceCount', obj.getInheritedInstanceCount())