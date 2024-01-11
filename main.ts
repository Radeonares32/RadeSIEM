import { createSession,TCPTracker,decode } from 'pcap'
import fs from 'fs'

const session = createSession("wlo1",{monitor:false,promiscuous:true})
const tcpTracker = new TCPTracker()

var destIpv4Object:ILogger[] = []

session.on("data",async (raw_packet)=>{
  console.log(raw_packet)
})

session.on('packet',async (raw_packet)=>{ 
    const data = await decode.packet(await raw_packet)
    setTimeout(async ()=>{
    try {
     const destIpv4:any[] = await data.payload.payload.daddr.addr
     const srcIpv4:any[] = await data.payload.payload.saddr.addr
     const port = await data.payload
     console.log(port)
     await log([
      {
      sAddr:srcIpv4.join('.').toString(),
      dAddr:destIpv4.join('.').toString()
      }])
    }
    catch(err:any) {
      console.log(err.message)
    }
  },500)
})

setTimeout(()=>{
  console.log(destIpv4Object)
},10000)



interface ILogger {
  sAddr:string
  dAddr:string
}

async function log(data:ILogger[]) {
  const fileName = "logs.log"
  if(!(await fs.existsSync(fileName))) {
    fs.open(fileName,'w',async (err:any)=>{
      if(err) {
        return err
      }
      else {
        await fs.writeFileSync(fileName,JSON.stringify(data)+"\n")
        
      }
    })
  }
  else {
     await fs.appendFile(fileName,JSON.stringify(data),(err)=>{
      if(err){
        return err
      }
    })
  }

}
