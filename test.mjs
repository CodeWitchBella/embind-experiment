const mod = await (await import('./a.out.js')).default()
//console.log(mod)
//const rootClass = mod.getRootValue()
//console.log('abc')
//console.log(rootClass.field.num)


//mod.getRootValue()
const rootClass = new mod.RootClass()
rootClass.field
rootClass.field.delete()
rootClass.delete()
//rootClass.delete()

//const wrapper = new mod.WrapperClass()
//const field = wrapper.field
//field.delete()
//wrapper.delete()
console.log('leaked objects:', mod.readCounter())
